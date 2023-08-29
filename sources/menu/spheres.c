/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 17:58:02 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	display_sphere_commands(t_world *w, int id)
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
}

t_menu_state	handle_sphere_choice(int keycode, t_world *w)
{
	if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else if (keycode >= ONE && keycode <= NINE)
		return (display_sphere_commands(w, keycode - '0' - 1), CHANGE_SPHERE);
	return (CHOOSE_SPHERE);
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
		if (shape->type != SPHERE)
			continue ;
		mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			90 + (++w->menu.i * 20), 0xFFFF00, \
				nc_itoa(w->menu.iterator + 1));
		mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			90 + (w->menu.i * 20), 0xFFFFFF, "- SPHERE");
		w->menu.ids[w->menu.iterator] = shape->id;
		w->menu.iterator++;
	}
}

void	display_sphere_choice_menu(t_world *w)
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
}