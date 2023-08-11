/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:05:45 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/11 16:41:51 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	intersects(t_shape *shape, t_ray *ray, t_hit *inter)
{
	if (shape->type == SPHERE)
		return (sphere_intersect(&shape->data.sp, ray, inter));
	else if (shape->type == PLANE)
		return (plane_intersect(&shape->data.pl, ray, inter));
	else if (shape->type == CYLINDER)
		return (cylinder_intersect(&shape->data.cy, ray, inter));
	return (false);
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
		if (!intersects(shape, ray, &tmp) || tmp.t >= closest->t)
			continue ;
		*closest = tmp;
		closest->ray = *ray;
		closest->shape = shape;
		closest->point = ray_at(ray, closest->t);
		closest->normal = vec3_normalize(shape_normal(closest, ray));
	}
	return (closest->shape != NULL);
}

int	render(t_world *w)
{
	t_vec3	coords;
	t_vec3	factors;
	t_ray	ray;
	t_hit	closest;

	coords.y = -1;
	while (++coords.y < HEIGHT)
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
				illuminate(w, &closest);
			put_pixel(w, closest.color, coords.x, coords.y);
		}
	}
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.img, 0, 0);
	return (0);
}
