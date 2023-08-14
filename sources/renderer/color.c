/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:22:56 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/14 13:09:28 by ncarvalh         ###   ########.fr       */
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

t_color	color_from_strings(char **rgb)
{
	return ((t_color)
		{
			.r = nc_atoi(rgb[R]),
			.g = nc_atoi(rgb[G]),
			.b = nc_atoi(rgb[B]),
		}
	);
}

