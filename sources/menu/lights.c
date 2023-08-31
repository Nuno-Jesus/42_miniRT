/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/08/31 16:12:48 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	display_light_commands(t_world *w, int id)
{
	w->menu.id = id;
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display(w, (t_xy){10, 53}, 0xFFFFFF, "LIGHT");
	display(w, (t_xy){9, 64}, 0xFFA160, "-----");
	light_info1(w);
	light_info2(w);
}

t_menu_state	handle_light_choice(int keycode, t_world *w)
{
	if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else if (keycode < ONE || keycode > NINE)
		return (CHOOSE_LIGHT);
	else if (keycode - ONE < (int)w->lights->size)
		return (display_light_commands(w, keycode - ONE), CHANGE_LIGHT);
	return (CHOOSE_LIGHT);
}

void	display_available_lights(t_world *w, t_vector *l)
{
	uint32_t	i;
	t_light		*light;
	int			color;

	i = -1;
	w->menu.i = -1;
	w->menu.id = 0;
	w->menu.iterator = 0;
	while (++i < l->size)
	{
		light = nc_vector_at(l, i);
		color = color_to_int(light->color);
		display(w, (t_xy){5, 90 + (++w->menu.i * 20)}, \
			0xFFFF00, nc_itoa(i + 1));
		display(w, (t_xy){25, 90 + (w->menu.i * 20)}, \
			color, "- LIGHT");
		w->menu.iterator++;
	}
}

void	display_light_choice_menu(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display(w, (t_xy){10, 53}, 0xFFFFFF, "LIGHTS");
	display(w, (t_xy){9, 64}, 0xFFA160, "------");
	display_available_lights(w, w->lights);
	display(w, (t_xy){5, 90 + (++w->menu.i * 20 + 15)}, 0xFFFF00, "FOR MORE INFO");
	display(w, (t_xy){5, 90 + (w->menu.i * 20 + 35)}, 0xFFFF00, "PRESS A NUMBER");
	display(w, (t_xy){5, 90 + (++w->menu.i * 20 + 50)}, 0xFF0000, "Q");
	display(w, (t_xy){25, 90 + (w->menu.i * 20 + 50)}, 0xFFFFFF, "- Previous Menu");
}