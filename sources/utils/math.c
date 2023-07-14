/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:03:20 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/14 16:27:19 by ncarvalh         ###   ########.fr       */
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

int	quadformula(float a, float b, float c, float *roots)
{
	float	x1;
	float	x2;
	float	delta;

	delta = determinant(a, b, c);
	if (delta == 0)
		return (0);
	x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);
	if (x1 < x2)
	{
		roots[0] = x1;
		roots[1] = x2;
	}
	else
	{
		roots[0] = x2;
		roots[1] = x1;
	}
	return (delta);
}