/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:23:25 by crypto            #+#    #+#             */
/*   Updated: 2023/08/09 19:21:45 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
	Given a ray L that has an angle A with the normal of a shape,
	the diffuse illumination (ID) is given by:

	ID = K * shape_color * cos(A)
	K - diffuse coefficient (depends on the material)
	shape_color - ineherent color of the shape
	cos(A) - cossine of the angle between N and L
	
*/
t_color	diffuse(t_light* bulb, t_intersection *inter, double k)
{
	t_vec3	light_dir;
	t_color	diff_color;
	double	cos_angle;
	// double	light_dist;
	double	diffuse_ratio;
	
	light_dir = vec3_sub(bulb->center, inter->point);
	cos_angle = vec3_dot(inter->normal, vec3_normalize(light_dir));
	// light_dist = vec3_module(light_dir);
	diffuse_ratio = k * cos_angle;
	// printf("diffuse_ratio: %lf\n", diffuse_ratio);
	//printf("cossine: %lf -> ", cos_angle);
	// vec3_print(inter->point);
	
	// if (cos_angle <= 0.0)
	// {
	// 	diffuse_ratio = 0.0;
	// }
	diff_color = color_mult(inter->color, diffuse_ratio);
	//color_print(&diff_color);
	return (diff_color);
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