/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/08/23 12:45:19 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	light(t_world *w, int id)
{
	t_light	*light;

	w->helper.light_id = id;
	light = nc_vector_at(w->lights, id);
	(void)light;
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	menu_text(w);
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 53, \
		0xFFFFFF, "LIGHT");
	mlx_string_put(w->disp.mlx, w->disp.win, 9, 64, \
		0xFFA160, "-----");
	light_info1(w);
	light_info2(w);
	light_info3(w);
	mlx_hook(w->disp.win, KeyPress, KeyPressMask, move_light, w);
}

int		light_menu(int keycode, t_world *w)
{
	if (keycode == ESC)
		quit(w);
	else if (keycode == ONE)
		light(w, 0);
	else if (keycode == TWO && w->helper.n_lights > 1)
		light(w, 1);
	else if (keycode == THREE && w->helper.n_lights > 2)
		light(w, 2);
	else if (keycode == FOUR && w->helper.n_lights > 3)
		light(w, 3);
	else if (keycode == FIVE && w->helper.n_lights > 4)
		light(w, 4);
	else if (keycode == SIX && w->helper.n_lights > 5)
		light(w, 5);
	else if (keycode == SEVEN && w->helper.n_lights > 6)
		light(w, 6);
	else if (keycode == EIGHT && w->helper.n_lights > 7)
		light(w, 7);
	else if (keycode == NINE && w->helper.n_lights > 8)
		light(w, 8);
	else if (keycode == Q)
		menu_execution(w);
	return (keycode);
}

void	display_lights(t_world *w, t_vector *l)
{
	uint32_t	i;

	i = -1;
	w->helper.i = -1;
	w->helper.n_lights = 0;
	while (++i < l->size)
	{
		mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			90 + (++w->helper.i * 20), 0xFFFF00, nc_itoa(i + 1));
		mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			90 + (w->helper.i * 20), 0xFFFFFF, "- LIGHT");
		w->helper.n_lights++;
	}
}

void	change_light(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	menu_text(w);
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 53, \
		0xFFFFFF, "LIGHTS");
	mlx_string_put(w->disp.mlx, w->disp.win, 9, 64, \
		0xFFA160, "------");
	display_lights(w, w->lights);
		mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		90 + (++w->helper.i * 20 + 15), 0xFFFF00, "FOR MORE INFO");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		90 + (w->helper.i * 20 + 35), 0xFFFF00, "PRESS A NUMBER");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		90 + (++w->helper.i * 20 + 50), 0xFF0000, "Q");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			90 + (w->helper.i * 20 + 50), 0xFFFFFF, "- Previous Menu");
	mlx_hook(w->disp.win, KeyPress, KeyPressMask, light_menu, w);
}