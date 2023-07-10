/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:12:59 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/10 19:25:45 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	put_pixel(t_root *r, t_color c, int x, int y)
{
	char	*dst;

	dst = r->disp.addr + (y * WIDTH + x) * (r->disp.bpp / 8);
	*(unsigned int *)dst = (c.t << 24 | c.r << 16 | c.g << 8 | c.b);
}

// t_color	get_pixel(t_root *r, int x, int y)
// {
// 	char	*pixel;

// 	pixel = r->disp.addr + (y * WIDTH + x) * (r->disp.bpp / 8);
// 	return (color_from_string(pixel));
// }
