/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:06:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 19:20:04 by crypto           ###   ########.fr       */
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

