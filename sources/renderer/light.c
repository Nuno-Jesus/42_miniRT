/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:23:25 by crypto            #+#    #+#             */
/*   Updated: 2023/09/04 13:35:23 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	color_to_int(t_color color)
{
	return ((int)color.r << 16 | (int)color.g << 8 | (int)color.b);
}

void	illuminate(t_world *world, t_hit *closest)
{
	uint32_t	i;
	t_light		*bulb;
	t_color		color;

	i = -1;
	apply_texture(closest);
	color = ambient(&world->ambient, closest->color);
	while (++i < world->lights->size)
	{
		bulb = nc_vector_at(world->lights, i);
		if (is_shadowed(world, bulb, closest))
			continue ;
		color = color_add(color, diffuse(bulb, closest));
		color = color_add(color, specular(bulb, closest));
	}
	closest->color = color;
}

t_color	ambient(t_light *ambient, t_color color)
{
	t_color	amb_ratios;

	amb_ratios = color_mult(ambient->color, 1.0 / 255);
	color.r *= amb_ratios.r;
	color.g *= amb_ratios.g;
	color.b *= amb_ratios.b;
	return (color_mult(color, ambient->ratio));
}

t_color	diffuse(t_light *bulb, t_hit *inter)
{
	t_vec3	light_dir;
	t_color	diff_color;
	double	cos_angle;
	double	diff_ratio;
	double	attenuation;

	light_dir = vec3_sub(bulb->center, inter->point);
	attenuation = MIN(1.0, 90.0 / vec3_length(light_dir));
	cos_angle = vec3_cossine(inter->normal, light_dir);
	diff_ratio = MAX(0.0, KD * bulb->ratio * cos_angle * attenuation);
	diff_color = color_mult(inter->color, diff_ratio);
	diff_color = color_mix(diff_color, bulb->color);
	return (diff_color);
}

t_color	specular(t_light *bulb, t_hit *closest)
{
	double	spec_ratio;
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
	spec_ratio = closest->shape->ks * bulb->ratio * pow(cosine,
			closest->shape->shininess);
	return (color_mix(color_mult(closest->color, spec_ratio), bulb->color));
}
