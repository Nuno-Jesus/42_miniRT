/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:22:56 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/18 19:27:26 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color	color_new(int r, int g, int b)
{
	return ((t_color)
		{
			.r = nc_clamp(r, 0, 255),
			.g = nc_clamp(g, 0, 255),
			.b = nc_clamp(b, 0, 255)
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

t_color	color_mix(t_color color, t_color mixer)
{
	t_color	ratios;

	ratios = color_mult(mixer, 1.0/255.0);
	color.r *= ratios.r;
	color.g *= ratios.g;
	color.b *= ratios.b;
	return (color);
}

t_color	color_from_strings(char **rgb)
{
	return ((t_color)
		{
			.r = nc_clamp(nc_atoi(rgb[R]), 0, 255),
			.g = nc_clamp(nc_atoi(rgb[G]), 0, 255),
			.b = nc_clamp(nc_atoi(rgb[B]), 0, 255),
		}
	);
}
