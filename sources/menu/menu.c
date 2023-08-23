/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:34:07 by maricard          #+#    #+#             */
/*   Updated: 2023/08/23 10:42:34 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		menu_keys(int keycode, t_world *w)
{
	if (keycode == Q)
		mlx_hook(w->disp.win, KeyPress, KeyPressMask, on_keypress, w);
	else if (keycode == ESC)
		quit(w);
	else if (keycode == ONE)
		change_camera(w);
	else if (keycode == TWO)
		change_ambient_light(w);
	else if (keycode == THREE)
		change_light(w);
	//else if (keycode == FOUR)
	//	change_sphere(w);
	//else if (keycode == FIVE)
	//	change_plane(w);
	//else if (keycode == SIX)
	//	change_cylinder(w);
	//else if (keycode == SEVEN)
	//	change_cone(w);
	return (keycode);
}

void	menu_text(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 6, 0, 0xFFA160, "-----");
	mlx_string_put(w->disp.mlx, w->disp.win, 12, 13, 0xFFFFFF, "MENU");
	mlx_string_put(w->disp.mlx, w->disp.win, 6, 26, 0xFFA160, "-----");
	mlx_string_put(w->disp.mlx, w->disp.win, 0, 11, 0xFFA160, "|");
	mlx_string_put(w->disp.mlx, w->disp.win, 54, 11, 0xFFA160, "|");
}

void	menu_execution(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	menu_text(w);
	write_shapes(w);
	mlx_hook(w->disp.win, KeyPress, KeyPressMask, menu_keys, w);
}

void	render_menu(t_world *w)
{
	w->disp.menu = mlx_new_image(w->disp.mlx, WIDTH/6, HEIGHT);
	menu_execution(w);
}