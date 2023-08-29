/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:58:12 by maricard          #+#    #+#             */
/*   Updated: 2023/08/23 20:04:55 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	plane_info1(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 90, 0xFFFF00, "W");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 110, 0xFFFF00, "S");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 130, 0xFFFF00, "A");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 150, 0xFFFF00, "D");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 180, 0xFFFF00, "UP");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 200, 0xFFFF00, "DOWN");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 230, 0xFFFF00, "1");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 250, 0xFFFF00, "2");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 270, 0xFFFF00, "3");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 290, 0xFFFF00, "4");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 310, 0xFFFF00, "5");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 340, 0xFF0000, "Q");
}

void	plane_info2(t_world *w)
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
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 230, \
		0xFFFFFF, " - Color white");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 250, \
		0xFFFFFF, " - Color Yellow");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 270, \
		0xFFFFFF, " - Color Red");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 290, \
		0xFFFFFF, " - Color Green");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 310, \
		0xFFFFFF, " - Color Blue");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 340, \
		0xFFFFFF, " - Previous menu");	
}
