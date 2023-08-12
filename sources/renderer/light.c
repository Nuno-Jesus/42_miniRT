/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:23:25 by crypto            #+#    #+#             */
/*   Updated: 2023/08/12 18:42:03 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	hits(t_vector *shapes, t_shape *own, t_ray *ray, double max_t)
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

bool	shadowed(t_world *world, t_hit *closest)
{
	t_vec3	light_dir;
	t_light	*light;
	t_ray	ray;

	light = nc_vector_at(world->lights, 0);
	light_dir = vec3_sub(light->center, closest->point);
	ray.origin = vec3_add(closest->point, VEC_EPSILON);
	ray.direction = vec3_normalize(light_dir);
	return (hits(world->shapes, closest->shape, &ray, vec3_length(light_dir)));
}

void	illuminate(t_world *world, t_hit *closest)
{
	t_color	color;
	t_light	*bulb;

	bulb = nc_vector_at(world->lights, 0); 
	color = ambient(closest->color, world->ambient.ratio);
	if (!shadowed(world, closest))
		color = color_add(color, diffuse(bulb, closest, bulb->ratio));
	closest->color = color;
}

/* 
	Ambient illumination (IA) is given by:

	IA = k * shape_color

	k - ambient illumination coefficient
	shape_color - color of the shape
	
*/
t_color	ambient(t_color	color, double ratio)
{
	return (color_mult(color, ratio));
}

/*
	Given a ray L that has an angle A with the normal of a shape,
	the diffuse illumination (ID) is given by:

	ID = K * shape_color * cos(A)
	K - diffuse coefficient (depends on the material)
	shape_color - ineherent color of the shape
	cos(A) - cossine of the angle between N and L
	
*/
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
