/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/08/31 16:12:21 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	display_cylinder_commands(t_world *w, int id)
{
	w->menu.id = id;
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display(w, (t_xy){10, 53} ,0xFFFFFF, "CYLINDERS");
	display(w, (t_xy){9, 64} ,0xFFA160, "---------");
	cylinder_info1(w);
	cylinder_info2(w);
}

t_menu_state	handle_cylinder_choice(int keycode, t_world *w)
{
	if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else if (keycode >= ONE && keycode <= NINE)
		return (display_cylinder_commands(w, keycode - ONE), CHANGE_CYLINDER);
	return (CHOOSE_CYLINDER);
}

void	display_cylinder(t_world *w, t_vector *l)
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
		if (shape->type != CYLINDER)
			continue ;
		color = color_to_int(shape->data.cy.color);
		display(w, (t_xy){5, 90 + (++w->menu.i * 20)}, \
			0xFFFF00,nc_itoa(w->menu.iterator + 1));
		display(w, (t_xy){25, 90 + (w->menu.i * 20)}, \
			color, "- CYLINDER");
		w->menu.ids[w->menu.iterator] = shape->id;
		w->menu.iterator++;
	}
}

void	display_cylinder_choice_menu(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display(w, (t_xy){10, 53} ,0xFFFFFF, "CYLINDER");
	display(w, (t_xy){9, 64} ,0xFFA160, "--------");
	display_cylinder(w, w->shapes);
	display(w, (t_xy){5, 90 + (++w->menu.i * 20 + 15)}, \
		0xFFFF00, "FOR MORE INFO");
	display(w, (t_xy){5, 90 + (w->menu.i * 20 + 35)}, \
		0xFFFF00, "PRESS A NUMBER");
	display(w, (t_xy){5, 90 + (++w->menu.i * 20 + 50)}, \
		0xFF0000, "Q");
	display(w, (t_xy){25,90 + (w->menu.i * 20 + 50)}, \
		0xFFFFFF, "- Previous Menu");
}