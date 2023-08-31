/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:34:07 by maricard          #+#    #+#             */
/*   Updated: 2023/08/31 16:05:57 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_menu_state	handle_closed_menu(int keycode, t_world *w)
{
	if (keycode != M)
		return (MENU_CLOSED);
	display_main_menu(w);
	return (MENU_OPENED);
}

t_menu_state	handle_opened_menu(int keycode, t_world *w)
{
	if (keycode == ONE)
		return (display_camera_menu(w), CHANGE_CAMERA);
	else if (keycode == TWO)
		return (display_amb_light_menu(w), CHANGE_AMBIENT_LIGHT);
	else if (keycode == THREE)
		return (display_light_choice_menu(w), CHOOSE_LIGHT);
	else if (keycode == FOUR)
		return (display_sphere_choice_menu(w), CHOOSE_SPHERE);
	else if (keycode == FIVE)
		return (display_plane_choice_menu(w), CHOOSE_PLANE);
	else if (keycode == SIX)
		return (display_cylinder_choice_menu(w), CHOOSE_CYLINDER);
	else if (keycode == SEVEN)
		return (display_cone_choice_menu(w), CHOOSE_CONE);
	else if (keycode == Q)
		return (multithread(w), MENU_CLOSED);
	return (MENU_OPENED);
}


void	display_menu_title(t_world *w)
{
	display(w, (t_xy){6, 0}, 0xFFA160, "-----");
	display(w, (t_xy){12, 13}, 0xFFFFFF, "MENU");
	display(w, (t_xy){6, 26}, 0xFFA160, "-----");
	display(w, (t_xy){0, 11}, 0xFFA160, "|");
	display(w, (t_xy){54, 11}, 0xFFA160, "|");
}

void	display_main_menu(t_world *w)
{
	w->menu.i = 0;
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display_menu_entites(w);
}
