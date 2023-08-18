/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:23:25 by crypto            #+#    #+#             */
/*   Updated: 2023/08/18 18:47:44 by ncarvalh         ###   ########.fr       */
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


/**
 * !@brief Calculates the specular lighting in a given point
 * 
 * !The specular lighting in a given point is calculated given the following formula
 * 
 * !	Ie = Ke * Ip * (N.H)^n
 * 
 * !Ie - specular lighting
 * !Ke - specular constant (depends on the material)
 * !Ip - light source intensity 
 * !H - half vector (the normalized vector between the light and camera directions)
 * !N - the normal vector in that surface
 * !n - a value depending on the material (high for highly polished surfaces)
 */
t_color	specular(t_light *bulb, t_hit *closest)
{
	double	specular_ratio;
	t_vec3	light_dir;
	t_vec3	camera_dir;
	t_vec3	half_vector;
	double	cosine;

	if (closest->shape->shininess < 1.0)
		return (BLACK);
	light_dir = vec3_sub(bulb->center, closest->point);
	camera_dir = vec3_scale(closest->ray.direction, -1);
	camera_dir = vec3_normalize(camera_dir);
	half_vector = vec3_normalize(vec3_add(camera_dir, light_dir));
	cosine = MAX(0.0, vec3_dot(half_vector, closest->normal));
	specular_ratio = closest->shape->ks * bulb->ratio * pow(cosine, closest->shape->shininess);
	return (color_mult(closest->color, specular_ratio));
}

void	illuminate(t_world *world, t_hit *closest)
{
	uint32_t	i;
	t_light		*bulb;
	t_color		color;
	t_color		component;

	color = ambient(closest->color, world->ambient.ratio);
	i = -1;
	while (++i < world->lights->size)
	{
		bulb = nc_vector_at(world->lights, i);
		if (is_shadowed(world, bulb, closest))
			continue ;
		component = diffuse(bulb, closest);
		color = color_add(color, component);
		component = specular(bulb, closest);
		color = color_add(color, component);
	}
	closest->color = color;
}

t_color	ambient(t_color	color, double ratio)
{
	return (color_mult(color, ratio));
}

t_color	diffuse(t_light *bulb, t_hit *inter)
{
	t_vec3	light_dir;
	t_color	diff_color;
	double	cos_angle;
	double	diffuse_ratio;
	double	attenuation;

	light_dir = vec3_sub(bulb->center, inter->point);
	attenuation = MIN(1.0, 90.0 / vec3_length(light_dir));
	cos_angle = vec3_cossine(inter->normal, light_dir);
	diffuse_ratio = KD * bulb->ratio * cos_angle * attenuation;
	diff_color = color_mult(inter->color, diffuse_ratio);
	return (diff_color);
}

