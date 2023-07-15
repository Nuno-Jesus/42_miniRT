/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:22:56 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/14 18:11:54 by ncarvalh         ###   ########.fr       */
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

void	color_print(t_color *color)
{
	printf("#%02X%02X%02X\n", color->r, color->g, color->b);
}

