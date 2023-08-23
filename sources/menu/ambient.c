/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/08/23 12:30:23 by maricard         ###   ########.fr       */
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

int		move_ambient(int keycode, t_world *w)
{
	if (keycode == LEFT)
		w->ambient.ratio += 0.1;
	else if (keycode == RIGHT)
		w->ambient.ratio -= 0.1;
	else if (keycode == Q)
	{
		menu_execution(w);
		return (keycode);
	}
	else if (keycode == ESC)
		quit(w);
	else
		return (keycode);
	multithread(w);
	change_ambient_light(w);
	return (keycode);
}

void	change_ambient_light(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	menu_text(w);
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 53, \
		0xFFFFFF, "AMBIENT LIGHT");
	mlx_string_put(w->disp.mlx, w->disp.win, 9, 64, \
		0xFFA160, "-------------");
	ambient_info1(w);
	ambient_info2(w);
	mlx_hook(w->disp.win, KeyPress, KeyPressMask, move_ambient, w);
}