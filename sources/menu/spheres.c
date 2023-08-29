/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 16:47:43 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	sphere(t_world *w, int id)
{
	w->menu.id = id;
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 53, \
		0xFFFFFF, "SHEPRES");
	mlx_string_put(w->disp.mlx, w->disp.win, 9, 64, \
		0xFFA160, "-------");
	sphere_info1(w);
	sphere_info2(w);
	sphere_info3(w);
	mlx_hook(w->disp.win, KeyPress, KeyPressMask, move_sphere, w);
}

int		sphere_menu(int keycode, t_world *w)
{
	if (keycode == ESC)
		quit(w);
	else if (keycode == ONE)
		sphere(w, 0);
	else if (keycode == TWO && w->menu.iterator > 1)
		sphere(w, 1);
	else if (keycode == THREE && w->menu.iterator > 2)
		sphere(w, 2);
	else if (keycode == FOUR && w->menu.iterator > 3)
		sphere(w, 3);
	else if (keycode == FIVE && w->menu.iterator > 4)
		sphere(w, 4);
	else if (keycode == SIX && w->menu.iterator > 5)
		sphere(w, 5);
	else if (keycode == SEVEN && w->menu.iterator > 6)
		sphere(w, 6);
	else if (keycode == EIGHT && w->menu.iterator > 7)
		sphere(w, 7);
	else if (keycode == NINE && w->menu.iterator > 8)
		sphere(w, 8);
	else if (keycode == Q)
		display_main_menu(w);
	return (keycode);
}

void	display_sphere(t_world *w, t_vector *l)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	w->menu.i = -1;
	w->menu.iterator = 0;
	shape = NULL;
	while (++i < l->size)
	{
		shape = nc_vector_at(l, i);
		if (shape->type == SPHERE)
		{
			mlx_string_put(w->disp.mlx, w->disp.win, 5, \
				90 + (++w->menu.i * 20), 0xFFFF00, \
					nc_itoa(w->menu.iterator + 1));
			mlx_string_put(w->disp.mlx, w->disp.win, 25, \
				90 + (w->menu.i * 20), 0xFFFFFF, "- SPHERE");
			w->menu.ids[w->menu.iterator] = shape->id;
			w->menu.iterator++;
		}
	}
}

void	handle_sphere_choice(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 53, \
		0xFFFFFF, "SPHERE");
	mlx_string_put(w->disp.mlx, w->disp.win, 9, 64, \
		0xFFA160, "------");
	display_sphere(w, w->shapes);
		mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		90 + (++w->menu.i * 20 + 15), 0xFFFF00, "FOR MORE INFO");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		90 + (w->menu.i * 20 + 35), 0xFFFF00, "PRESS A NUMBER");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		90 + (++w->menu.i * 20 + 50), 0xFF0000, "Q");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			90 + (w->menu.i * 20 + 50), 0xFFFFFF, "- Previous Menu");
	mlx_hook(w->disp.win, KeyPress, KeyPressMask, sphere_menu, w);
}