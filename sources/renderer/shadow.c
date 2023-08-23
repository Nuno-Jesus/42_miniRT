/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:04:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/18 19:07:47 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_obscured(t_vector *shapes, t_shape *own, t_ray *ray, double max_t)
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
		if (shape->id == own->id)
			continue ;
		if (intersects(shape, ray, &tmp) && tmp.t < max_t)
			return (true);
	}
	return (false);
}

bool	is_shadowed(t_world *world, t_light *bulb, t_hit *closest)
{
	t_vec3	light_dir;
	t_ray	ray;
	double	light_distance;

	light_dir = vec3_sub(bulb->center, closest->point);
	light_distance = vec3_length(light_dir);
	ray.origin = vec3_add(closest->point, VEC_EPSILON);
	ray.direction = vec3_normalize(light_dir);
	return (is_obscured(world->shapes, closest->shape, &ray, light_distance));
}
