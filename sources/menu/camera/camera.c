/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:40:42 by maricard          #+#    #+#             */
/*   Updated: 2023/09/04 10:36:08 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	else if (keycode == LEFT)
		w->camera.normal = vec3_rotate(w->camera.normal, Y, -ROTATE);
	else if (keycode == RIGHT)
		w->camera.normal = vec3_rotate(w->camera.normal, Y, ROTATE);
	else if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else
		return (CHANGE_CAMERA);
	init_viewport(w);
	multithread(w);
	display_camera_menu(w);
	return (CHANGE_CAMERA);
}

void	display_camera_info(t_world *w)
{
	display(w, (t_xy){10, 90,}, 0xFFFF00, "W");
	display(w, (t_xy){10, 110}, 0xFFFF00, "S");
	display(w, (t_xy){10, 130}, 0xFFFF00, "A");
	display(w, (t_xy){10, 150}, 0xFFFF00, "D");
	display(w, (t_xy){10, 180}, 0xFFFF00, "UP");
	display(w, (t_xy){10, 200}, 0xFFFF00, "DOWN");
	display(w, (t_xy){10, 220}, 0xFFFF00, "LEFT");
	display(w, (t_xy){10, 240}, 0xFFFF00, "RIGHT");
	display(w, (t_xy){10, 270}, 0xFF0000, "Q");
	display(w, (t_xy){30, 90}, 0xFFFFFF, " - Move Foward");
	display(w, (t_xy){20, 110}, 0xFFFFFF, " - Move Backwards");
	display(w, (t_xy){20, 130}, 0xFFFFFF, " - Move Left");
	display(w, (t_xy){20, 150}, 0xFFFFFF, " - Move Right");
	display(w, (t_xy){25, 180}, 0xFFFFFF, " - Go Up");
	display(w, (t_xy){45, 200}, 0xFFFFFF, " - Go Down");
	display(w, (t_xy){45, 220}, 0xFFFFFF, " - Rotate Left");
	display(w, (t_xy){55, 240}, 0xFFFFFF, " - Rotate Right");
	display(w, (t_xy){20, 270}, 0xFFFFFF, " - Previous menu");
}

void	display_camera_menu(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display(w, (t_xy){10, 53}, 0xFFFFFF, "CAMERA");
	display(w, (t_xy){9, 64}, 0xFFA160, "------");
	display_camera_info(w);
}
