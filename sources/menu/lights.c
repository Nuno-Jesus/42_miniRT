/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/08/22 23:05:14 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	light_info1(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 90, 0xFFFF00, "A");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 110, 0xFFFF00, "D");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 140, 0xFFFF00, "Q");
}

void	light_info2(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 90, \
		0xFFFFFF, " - Increase Intensity");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 110, \
		0xFFFFFF, " - Decrease Intensity");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 140, \
		0xFFFFFF, " - Close Menu");
}

int		move_light(int keycode, t_world *w)
{
	if (keycode == A)
		w->ambient.ratio += 0.1;
	else if (keycode == D)
		w->ambient.ratio -= 0.1;
	else if (keycode == Q)
	{
		menu_execution(w);
		return (keycode);
	}
	else if (keycode == ESC)
		quit(w);
	render(w);
	change_light(w);
	return (keycode);
}

void	display_lights(t_world *w, t_vector *l)
{
	uint32_t	i;

	i = -1;
	w->helper.i = -1;
	while (++i < l->size)
	{
		mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			110 + (w->helper.i * 20), 0xFFFF00, nc_itoa(i + 1));
		mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			110 + (w->helper.i * 20), 0xFFFFFF, "- LIGHT");
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
	//light_info1(w);
	//light_info2(w);
	mlx_hook(w->disp.win, KeyPress, KeyPressMask, move_light, w);
}