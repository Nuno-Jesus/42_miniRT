/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cones_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:58:12 by maricard          #+#    #+#             */
/*   Updated: 2023/08/25 17:26:16 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cone_info1(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 90, 0xFFFF00, "W");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 110, 0xFFFF00, "S");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 130, 0xFFFF00, "A");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 150, 0xFFFF00, "D");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 180, 0xFFFF00, "UP");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 200, 0xFFFF00, "DOWN");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 220, 0xFFFF00, "LEFT");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 240, 0xFFFF00, "RIGHT");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 270, 0xFFFF00, "C");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 290, 0xFFFF00, "V");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 320, 0xFFFF00, "1");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 340, 0xFFFF00, "2");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 360, 0xFFFF00, "3");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 380, 0xFFFF00, "4");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 400, 0xFFFF00, "5");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 430, 0xFF0000, "Q");
}

void	cone_info2(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 90, \
		0xFFFFFF, " - Move Foward");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 110, \
		0xFFFFFF, " - Move Backwards");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 130, \
		0xFFFFFF, " - Move Left");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 150, \
		0xFFFFFF, " - Move Right");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, 180, \
		0xFFFFFF, " - Go Up");
	mlx_string_put(w->disp.mlx, w->disp.win, 45, 200, \
		0xFFFFFF, " - Go Down");
	mlx_string_put(w->disp.mlx, w->disp.win, 45, 220, \
		0xFFFFFF, " - Increase radius");
	mlx_string_put(w->disp.mlx, w->disp.win, 50, 240, \
		0xFFFFFF, " - Decrease radius");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 270, \
		0xFFFFFF, " - Increase Height");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 290, \
		0xFFFFFF, " - Decrease Height");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 320, \
		0xFFFFFF, " - Color white");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 340, \
		0xFFFFFF, " - Color Yellow");
}

void	cone_info3(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 360, \
		0xFFFFFF, " - Color Red");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 380, \
		0xFFFFFF, " - Color Green");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 400, \
		0xFFFFFF, " - Color Blue");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 430, \
		0xFFFFFF, " - Previous menu");		
}
