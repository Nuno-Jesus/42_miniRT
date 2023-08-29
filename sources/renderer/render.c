/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:05:45 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/29 19:37:22 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	apply_texture(t_hit *closest)
{
	t_vec3	point;

	if (!closest->shape->is_textured)
		return ;
	point = closest->point;
	if ((int)(floor(point.x) + floor(point.y) + floor(point.z)) % 2)
		closest->color = BLACK;
	else 
		closest->color = WHITE;
}

bool	world_hit(t_vector *shapes, t_ray *ray, t_hit *closest)
{
	uint32_t	i;
	t_hit		tmp;
	t_shape		*shape;

	i = -1;
	tmp.t = INFINITY;
	tmp.shape = NULL;
	while (++i < shapes->size)
	{
		shape = nc_vector_at(shapes, i);
		if (!intersects(shape, ray, &tmp))
			continue ;
		if (tmp.t > closest->t)
			continue ;
		*closest = tmp;
		closest->ray = *ray;
		closest->shape = shape;
		closest->point = ray_at(ray, closest->t);
		closest->normal = vec3_normalize(shape_normal(closest, ray));
	}
	return (closest->shape != NULL);
}

void	compute_shapes_constants(t_vector *shapes)
{
	t_shape		*shape;
	t_cylinder	*cy;
	t_cone 		*co;
	uint32_t	i;

	i = -1;
	while (++i < shapes->size)
	{
		shape = nc_vector_at(shapes, i);
		if (shape->type == CYLINDER)
		{
			cy = &shape->data.cy;
			cy->cap1 = vec3_add(cy->center, \
				vec3_scale(cy->normal, -cy->height / 2.0));
			cy->cap2 = vec3_add(cy->center, \
				vec3_scale(cy->normal, cy->height / 2.0));
		}
		else if (shape->type == CONE)
		{
			co = &shape->data.co;
			co->angle = atan(co->radius / co->height);
			co->base = vec3_add(co->tip, vec3_scale(co->normal, co->height));
		}
	}
}

void	*render(t_runner *worker)
{
	t_vec3	coords;
	t_vec3	factors;
	t_ray	ray;
	t_hit	closest;
	t_world	*w;

	w = worker->world;
	coords.y = worker->min_y - 1;
	compute_shapes_constants(w->shapes);
	while (++coords.y < worker->max_y)
	{
		coords.x = -1;
		while (++coords.x < WIDTH)
		{
			closest.color = BLACK;
			closest.shape = NULL;
			closest.t = INFINITY;
			factors = pixels_to_viewport(coords.x, coords.y);
			ray = make_ray(w, factors);
			if (world_hit(w->shapes, &ray, &closest))
			{
				apply_texture(&closest);
				illuminate(w, &closest);
			}
			put_pixel(w, closest.color, coords.x, coords.y);
		}
	}
	return (NULL);
}
