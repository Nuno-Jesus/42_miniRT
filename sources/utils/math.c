/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:06:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 11:43:59 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	determinant(t_equation *eq)
{
	double	delta;

	delta = pow(eq->b, 2) - (4 * eq->a * eq->c);
	if (delta < 0)
		return (-1);
	return (delta);
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
		ray->distance = distance;
		ray->color = *color;
	}
}
