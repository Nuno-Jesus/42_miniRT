/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 16:02:32 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ambient_info1(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 90, 0xFFFF00, "LEFT");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 110, 0xFFFF00, "RIGHT");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 140, 0xFF0000, "Q");
}

void	ambient_info2(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 45, 90, \
		0xFFFFFF, " - Increase ratio");
	mlx_string_put(w->disp.mlx, w->disp.win, 50, 110, \
		0xFFFFFF, " - Decrease ratio");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 140, \
		0xFFFFFF, " - Previous menu");
}

t_menu_state	handle_amb_light_changes(int keycode, t_world *w)
{
	if (keycode == LEFT)
		w->ambient.ratio += 0.1;
	else if (keycode == RIGHT)
		w->ambient.ratio -= 0.1;
	else if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else
		return (CHANGE_AMBIENT_LIGHT);
	multithread(w);
	display_amb_light_menu(w);
	return (CHANGE_AMBIENT_LIGHT);
}

void	display_amb_light_menu(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	menu_text(w);
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 53, \
		0xFFFFFF, "AMBIENT LIGHT");
	mlx_string_put(w->disp.mlx, w->disp.win, 9, 64, \
		0xFFA160, "-------------");
	ambient_info1(w);
	ambient_info2(w);
}