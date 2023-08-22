/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:06:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/22 12:34:36 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double 	closest_value(double t1, double t2)
{
	if (t1 > EPSILON && t1 < t2)
		return (t1);
	else if (t2 > EPSILON)
		return (t2);
	else
		return (-1.0f);
}

double	determinant(t_equation *eq)
{
	double	delta;

	delta = pow(eq->b, 2) - (4 * eq->a * eq->c);
	if (delta < 0)
		return (-1);
	return (delta);
}

double	solve(t_equation *eq)
{
	double	delta;

	if (eq->a == 0.0 && eq->b != 0.0)
	{
		eq->t1 = -eq->c / eq->b;
		return (0);
	}
	else
	{
		delta = determinant(eq);
		if (delta < 0)
			return (-1);
		eq->t1 = (-eq->b - sqrt(delta)) / (2 * eq->a);
		eq->t2 = (-eq->b + sqrt(delta)) / (2 * eq->a);
		return (delta);
	}
}
