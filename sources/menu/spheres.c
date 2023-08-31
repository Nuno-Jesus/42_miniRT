/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/08/31 16:17:30 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	display_sphere_commands(t_world *w, int id)
{
	w->menu.id = id;
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display(w, (t_xy){10, 53}, 0xFFFFFF, "SHEPRES");
	display(w, (t_xy){9, 64}, 0xFFA160, "-------");
	sphere_info1(w);
	sphere_info2(w);
}

t_menu_state	handle_sphere_choice(int keycode, t_world *w)
{
	if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else if (keycode >= ONE && keycode <= NINE)
		return (display_sphere_commands(w, keycode - ONE), CHANGE_SPHERE);
	return (CHOOSE_SPHERE);
}

void	display_sphere(t_world *w, t_vector *l)
{
	uint32_t	i;
	t_shape		*shape;
	int 		color;

	i = -1;
	w->menu.i = -1;
	w->menu.iterator = 0;
	shape = NULL;
	while (++i < l->size)
	{
		shape = nc_vector_at(l, i);
		if (shape->type != SPHERE)
			continue ;
		color = color_to_int(shape->data.sp.color);
		display(w, (t_xy){5, 90 + (++w->menu.i * 20)}, \
			0xFFFF00, nc_itoa(w->menu.iterator + 1));
		display(w, (t_xy){25, 90 + (w->menu.i * 20)}, \
			color, "- SPHERE");
		w->menu.ids[w->menu.iterator] = shape->id;
		w->menu.iterator++;
	}
}

void	display_sphere_choice_menu(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display(w, (t_xy){10, 53}, 0xFFFFFF, "SPHERE");
	display(w, (t_xy){9, 64}, 0xFFA160, "------");
	display_sphere(w, w->shapes);
	display(w, (t_xy){5, 90 + (++w->menu.i * 20 + 15)}, \
		0xFFFF00, "FOR MORE INFO");
	display(w, (t_xy){5, 90 + (w->menu.i * 20 + 35)}, \
		0xFFFF00, "PRESS A NUMBER");
	display(w, (t_xy){5, 90 + (++w->menu.i * 20 + 50)}, \
		0xFF0000, "Q");
	display(w, (t_xy){25, 90 + (w->menu.i * 20 + 50)}, \
		0xFFFFFF, "- Previous Menu");
}