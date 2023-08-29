/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:34:07 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 15:59:43 by crypto           ###   ########.fr       */
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

// void	render_menu(t_world *w)
// {
// 	w->disp.menu = mlx_new_image(w->disp.mlx, WIDTH/6, HEIGHT);
// 	display_main_menu(w);
// }

t_menu_state	handle_opened_menu(int keycode, t_world *w)
{
	if (keycode == ONE)
		return (display_camera_menu(w), CHANGE_CAMERA);
	else if (keycode == TWO)
		return (display_amb_light_menu(w), CHANGE_AMBIENT_LIGHT);
	// else if (keycode == THREE)
	// 	return (handle_light_choice(w));
	// else if (keycode == FOUR)
	// 	return (handle_sphere_choice(w));
	// else if (keycode == FIVE)
	// 	return (handle_plane_choice(w));
	// else if (keycode == SIX)
	// 	return (handle_cylinder_choice(w));
	// else if (keycode == SEVEN)
	// 	return (handle_cone_choice(w));
	else if (keycode == Q)
		return (multithread(w), MENU_CLOSED);
	return (MENU_OPENED);
}

// void	main_menu(t_world *w)
// {
// 	multithread(w);
// 	mlx_hook(w->disp.win, KeyPress, KeyPressMask, on_keypress, w);
// }

void	menu_text(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 6, 0, 0xFFA160, "-----");
	mlx_string_put(w->disp.mlx, w->disp.win, 12, 13, 0xFFFFFF, "MENU");
	mlx_string_put(w->disp.mlx, w->disp.win, 6, 26, 0xFFA160, "-----");
	mlx_string_put(w->disp.mlx, w->disp.win, 0, 11, 0xFFA160, "|");
	mlx_string_put(w->disp.mlx, w->disp.win, 54, 11, 0xFFA160, "|");
}

void	display_main_menu(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	menu_text(w);
	w->menu.i = 0;
	write_shapes(w);
}
