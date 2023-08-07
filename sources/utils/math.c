/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:06:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/07 15:38:45 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	determinant(double a, double b, double c)
{
	double	delta;

	delta = pow(b, 2) - (4 * a * c);
	if (delta < 0)
		return (0);
	else if (delta < EPSILON)
		return (1);
	else
		return (2);
}

int	formula(double a, double b, double c, double *root)
{
	double	delta;

	delta = determinant(a, b, c);
	if (delta < 0)
		return (-1);
	*root = (-b - sqrt(delta)) / (2 * a);	
	return (delta);
}

void	closest_point(double t, t_ray *ray, t_color *color)
{
	t_vec3	point;
	t_vec3	vec;
	double 	distance;

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
