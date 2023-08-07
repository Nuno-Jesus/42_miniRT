/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:23:25 by crypto            #+#    #+#             */
/*   Updated: 2023/08/07 20:51:13 by crypto           ###   ########.fr       */
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
t_color	diffuse(t_vec3 bulb, t_inter *inter, double k)
{
	double	cos_angle;
	t_color	diff_color;
	
	cos_angle = vec3_cos(vec3_sub(bulb, inter->point), inter->normal);
	// printf("cos_angle: %f\n", cos_angle);
	// if (cos_angle < 0.0f)
	// 	cos_angle = 0.0f;
	diff_color = color_mult(inter->color, k * fabs(cos_angle));
	// color_print(&diff_color);
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