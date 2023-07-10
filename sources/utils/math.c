/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:03:20 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/10 19:42:00 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	determinant(float a, float b, float c)
{
	float	delta;

	delta = pow(b, 2) - (4 * a * c);
	//Print the power of b and b
	// printf("b^2 = %f\n", pow(b, 2));
	// printf("a = %f\n", a);
	// printf("b = %f\n", b);
	// printf("c = %f\n", c);
	// printf("4*a*c = %f\n", 4 * a * c);
	// printf("delta = %f\n", delta);
	// printf("\n\t==END==\n\n");
	if (delta < 0)
		return (0);
	else if (delta < EPSILON)
		return (1);
	else
		return (2);
}

int	quadformula(float a, float b, float c)
{
	float	x1;
	float	x2;
	float	delta;
	
	delta = determinant(a, b, c);
	if (delta == 0)
		return (0);
	x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);
	return (delta);
}