/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:23:25 by crypto            #+#    #+#             */
/*   Updated: 2023/09/04 17:31:47 by maricard         ###   ########.fr       */
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

bool	is_shadowed(t_world *world, t_hit *closest)
{
	t_vec3	light_dir;
	t_light	*light;
	t_ray	ray;
	double	light_distance;

	if (!world->lights->size)
		return (false);
	light = nc_vector_at(world->lights, 0);
	light_dir = vec3_sub(light->center, closest->point);
	light_distance = vec3_length(light_dir);
	ray.origin = vec3_add(closest->point, VEC_EPSILON);
	ray.direction = vec3_normalize(light_dir);
	return (is_obscured(world->shapes, closest->shape, &ray, light_distance));
}

void	illuminate(t_world *world, t_hit *closest)
{
	t_color	color;
	t_light	*bulb;

	bulb = nc_vector_at(world->lights, 0); 
	color = ambient(closest->color, world->ambient.ratio);
	if (bulb && !is_shadowed(world, closest))
		color = color_add(color, diffuse(bulb, closest, bulb->ratio));
	closest->color = color;
}

t_color	ambient(t_color	color, double ratio)
{
	return (color_mult(color, ratio));
}

t_color	diffuse(t_light *bulb, t_hit *inter, double k)
{
	t_vec3	light_dir;
	t_color	diff_color;
	double	cos_angle;
	double	diffuse_ratio;
	double	attenuation;

	light_dir = vec3_sub(bulb->center, inter->point);
	attenuation = MIN(1.0, 90.0 / vec3_length(light_dir));
	cos_angle = vec3_cossine(inter->normal, light_dir);
	diffuse_ratio = k * cos_angle * attenuation;
	diff_color = color_mult(inter->color, diffuse_ratio);
	return (diff_color);
}
