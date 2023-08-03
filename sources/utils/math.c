/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:06:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/03 11:42:02 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	determinant(float a, float b, float c)
{
	float	delta;

	delta = pow(b, 2) - (4 * a * c);
	if (delta < 0)
		return (0);
	else if (delta < EPSILON)
		return (1);
	else
		return (2);
}

int	formula(float a, float b, float c, float *root)
{
	float	delta;

	delta = determinant(a, b, c);
	if (delta < 0)
		return (-1);
	*root = (-b - sqrt(delta)) / (2 * a);	
	return (delta);
}

void	closest_point(float t, t_ray *ray, t_color *color)
{
	t_vec3	point;
	t_vec3	vec;
	float 	distance;

	point = vec3_add(ray->origin, vec3_scale(ray->direction, t));
	vec = vec3_sub(point, ray->origin);
	distance = vec3_module(vec);
	if (distance < ray->distance + EPSILON)
	{
		// printf("Old color: ");
		// color_print(&ray->color);
		// printf("distance = %f\n", distance);
		// printf("ray->distance = %f\n", ray->distance);
		// printf("New color: ");
		// color_print(&ray->color);
		ray->distance = distance;
		ray->color = *color;
	}
}
