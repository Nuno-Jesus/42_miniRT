/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:05:45 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/31 18:51:10 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	get_uv(t_mesh *d, t_vec3 point, double *u, double *v)
{
	//vec3_print(d->pl.normal);
	if (d->pl.normal.x != 0 + EPSILON)
	{
		*u = point.z;
		*v = point.y;
	}
	else if (d->pl.normal.y != 0 + EPSILON)
	{
		*u = point.x;
		*v = point.z;
	}
	else if (d->pl.normal.z != 0 + EPSILON)
	{
		*u = point.x;
		*v = point.y;
	}
	else
	{
		*u = 0.0;
		*v = 0.0;
	}
}

void	apply_texture(t_hit *closest)
{
	t_vec3	point;
	double  u;
	double 	v;

	if (!closest->shape->is_textured)
		return ;
	point = closest->point;
	get_uv(&closest->shape->data, point, &u, &v);
	if ((int)(floor(u) + floor(v)) % 2)
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
