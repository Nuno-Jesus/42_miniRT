/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:06:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/07 16:48:23 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	determinant(t_equation *eq)
{
	double	delta;

	delta = pow(eq->b, 2) - (4 * eq->a * eq->c);
	if (delta < 0)
		return (0);
	else if (delta < EPSILON)
		return (1);
	else
		return (2);
}

int	quadformula(t_equation *eq)
{
	double	delta;

	delta = determinant(eq);
	if (delta < 0)
		return (-1);
	eq->t1 = (-eq->b - sqrt(delta)) / (2 * eq->a);	
	eq->t2 = (-eq->b + sqrt(delta)) / (2 * eq->a);	
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
