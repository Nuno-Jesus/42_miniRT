/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:23:25 by crypto            #+#    #+#             */
/*   Updated: 2023/08/10 17:55:48 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	illuminate(t_vector *lights, t_hit *closest, t_light *amb_light)
{
	t_color	final_color;
	t_light	*bulb;

	bulb = nc_vector_at(lights, 0); 
	final_color = ambient(closest->color, amb_light->ratio);
	final_color = color_add(final_color, diffuse(bulb, closest, bulb->ratio));
	closest->color = final_color;
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

	light_dir = vec3_sub(bulb->center, inter->point);
	cos_angle = vec3_dot(inter->normal, vec3_normalize(light_dir));
	diffuse_ratio = k * cos_angle;
	diff_color = color_mult(inter->color, diffuse_ratio);
	return (diff_color);
}

	// double	light_dist;
	//
	// light_dist = vec3_module(light_dir);
	// printf("diffuse_ratio: %lf\n", diffuse_ratio);
	//printf("cossine: %lf -> ", cos_angle);
	// vec3_print(inter->point);

	// if (cos_angle <= 0.0)
	// {
	// 	diffuse_ratio = 0.0;
	// }
	//color_print(&diff_color);
