/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 17:23:27 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	display_light_commands(t_world *w, int id)
{
	w->menu.id = id;
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 53, \
		0xFFFFFF, "LIGHT");
	mlx_string_put(w->disp.mlx, w->disp.win, 9, 64, \
		0xFFA160, "-----");
	light_info1(w);
	light_info2(w);
	light_info3(w);
}

t_menu_state	handle_light_choice(int keycode, t_world *w)
{
	if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else if (keycode < ONE || keycode > NINE)
		return (CHOOSE_LIGHT);
	else if (keycode - '0' - 1 < (int)w->lights->size)
		return (display_light_commands(w, keycode - '0' - 1), CHANGE_LIGHT);
	return (CHOOSE_LIGHT);
}

void	display_available_lights(t_world *w, t_vector *l)
{
	uint32_t	i;

	i = -1;
	w->menu.i = -1;
	w->menu.iterator = 0;
	while (++i < l->size)
	{
		mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			90 + (++w->menu.i * 20), 0xFFFF00, nc_itoa(i + 1));
		mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			90 + (w->menu.i * 20), 0xFFFFFF, "- LIGHT");
		w->menu.iterator++;
	}
}

void	display_light_choice_menu(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 53, \
		0xFFFFFF, "LIGHTS");
	mlx_string_put(w->disp.mlx, w->disp.win, 9, 64, \
		0xFFA160, "------");
	display_available_lights(w, w->lights);
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		90 + (++w->menu.i * 20 + 15), 0xFFFF00, "FOR MORE INFO");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		90 + (w->menu.i * 20 + 35), 0xFFFF00, "PRESS A NUMBER");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		90 + (++w->menu.i * 20 + 50), 0xFF0000, "Q");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			90 + (w->menu.i * 20 + 50), 0xFFFFFF, "- Previous Menu");
}