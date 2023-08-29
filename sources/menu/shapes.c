/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:50:10 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 16:47:54 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_flags(t_world *w)
{
	w->menu.sp_flag = 0;
	w->menu.pl_flag = 0;
	w->menu.cy_flag = 0;
	w->menu.co_flag = 0;
}

void	display_menu_entites(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 53, \
		0xFFFFFF, "LIST OF OBJECTS");
	mlx_string_put(w->disp.mlx, w->disp.win, 6, 64, \
		0xFFA160, "----------------");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, 85, 0xFFFF00, "1");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, 105, 0xFFFF00, "2");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, 125, 0xFFFF00, "3");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, 85, \
		0xFFFFFF, "- CAMERA");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, 105, \
		0xFFFFFF, "- AMBIENT LIGHT");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, 125, \
		0xFFFFFF, "- LIGHTS");
	search_shapes(w);
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		145 + (++w->menu.i * 20 + 15), 0xFFFF00, "FOR MORE INFO");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		145 + (w->menu.i * 20 + 35), 0xFFFF00, "PRESS A NUMBER");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		145 + (++w->menu.i * 20 + 50), 0xFF0000, "Q");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			145 + (w->menu.i * 20 + 50), 0xFFFFFF, "- Quit Menu");
}
