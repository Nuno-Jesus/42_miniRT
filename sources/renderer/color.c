/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:22:56 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/10 17:43:36 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	color_new(int r, int g, int b)
{
	return ((t_color)
		{
			.r = r,
			.g = g,
			.b = b
		}
	);
}

t_color	color_mult(t_color color, double k)
{
	return ((t_color)
		{
			.r = nc_clamp(color.r * k, 0, 255),
			.g = nc_clamp(color.g * k, 0, 255),
			.b = nc_clamp(color.b * k, 0, 255)
		}
	);
}

t_color	color_add(t_color c1, t_color c2)
{
	return ((t_color)
		{
			.r = nc_clamp(c1.r + c2.r, 0, 255),
			.g = nc_clamp(c1.g + c2.g, 0, 255),
			.b = nc_clamp(c1.b + c2.b, 0, 255),
		}
	);
}
