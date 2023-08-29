/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:40:42 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 16:02:20 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	camera_info1(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 90, 0xFFFF00, "W");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 110, 0xFFFF00, "S");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 130, 0xFFFF00, "A");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 150, 0xFFFF00, "D");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 180, 0xFFFF00, "UP");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 200, 0xFFFF00, "DOWN");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 230, 0xFF0000, "Q");
}

void	camera_info2(t_world *w)
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
		0xFFFFFF, " - Previous menu");
}

t_menu_state	handle_camera_changes(int keycode, t_world *w)
{
	if (keycode == W)
		w->camera.center.z += MOVE;
	else if (keycode == S)
		w->camera.center.z -= MOVE;
	else if (keycode == A)
		w->camera.center.x -= MOVE;
	else if (keycode == D)
		w->camera.center.x += MOVE;
	else if (keycode == UP)
		w->camera.center.y += MOVE;
	else if (keycode == DOWN)
		w->camera.center.y -= MOVE;
	else if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else
		return (CHANGE_CAMERA);
	multithread(w);
	display_camera_menu(w);
	return (CHANGE_CAMERA);
}

void	display_camera_menu(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	menu_text(w);
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 53, \
		0xFFFFFF, "CAMERA");
	mlx_string_put(w->disp.mlx, w->disp.win, 9, 64, \
		0xFFA160, "------");
	camera_info1(w);
	camera_info2(w);
}