/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/09/02 21:50:11 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	display_plane_commands(t_world *w, int id)
{
	w->menu.id = id;
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display(w, (t_xy){10, 53}, 0xFFFFFF, "PLANES");
	display(w, (t_xy){9, 64}, 0xFFA160, "-------");
	plane_info1(w);
	plane_info2(w);
}

void	display_plane_choice_menu(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display(w, (t_xy){10, 53}, 0xFFFFFF, "PLANE");
	display(w, (t_xy){9, 64}, 0xFFA160, "-----");
	display_planes(w, w->shapes);
	display(w, (t_xy){5, 90 + (++w->menu.i * 20 + 15)}, \
		0xFFFF00, "FOR MORE INFO");
	display(w, (t_xy){5, 90 + (w->menu.i * 20 + 35)}, \
		0xFFFF00, "PRESS A NUMBER");
	display(w, (t_xy){5, 90 + (++w->menu.i * 20 + 50)}, \
		0xFF0000, "Q");
	display(w, (t_xy){25, 90 + (w->menu.i * 20 + 50)}, \
		0xFFFFFF, "- Previous Menu");
}

void	display_planes(t_world *w, t_vector *l)
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
		if (shape->type != PLANE)
			continue ;
		color = color_to_int(shape->data.pl.color);
		display(w, (t_xy){5, 90 + (++w->menu.i * 20)}, \
			0xFFFF00, nc_itoa(w->menu.iterator + 1));
		display(w, (t_xy){25, 90 + (w->menu.i * 20)}, \
			color, "- PLANE");
		w->menu.ids[w->menu.iterator] = shape->id;
		w->menu.iterator++;
	}
}

void	plane_info1(t_world *w)
{
	display(w, (t_xy){10, 90}, 0xFFFF00, "W");
	display(w, (t_xy){10, 110}, 0xFFFF00, "S");
	display(w, (t_xy){10, 130}, 0xFFFF00, "A");
	display(w, (t_xy){10, 150}, 0xFFFF00, "D");
	display(w, (t_xy){10, 180}, 0xFFFF00, "UP");
	display(w, (t_xy){10, 200}, 0xFFFF00, "DOWN");
	display(w, (t_xy){10, 230}, 0xFFFF00, "1");
	display(w, (t_xy){10, 250}, 0xFFFF00, "2");
	display(w, (t_xy){10, 270}, 0xFFFF00, "3");
	display(w, (t_xy){10, 290}, 0xFFFF00, "4");
	display(w, (t_xy){10, 310}, 0xFFFF00, "5");
	display(w, (t_xy){10, 330}, 0xFFFF00, "6");
	display(w, (t_xy){10, 350}, 0xFFFF00, "7");
	display(w, (t_xy){10, 380}, 0xFF0000, "Q");
}

void	plane_info2(t_world *w)
{
	display(w, (t_xy){20, 90}, 0xFFFFFF, " - Move Foward");
	display(w, (t_xy){20, 110}, 0xFFFFFF, " - Move Backwards");
	display(w, (t_xy){20, 130}, 0xFFFFFF, " - Move Left");
	display(w, (t_xy){20, 150}, 0xFFFFFF, " - Move Right");
	display(w, (t_xy){25, 180}, 0xFFFFFF, " - Go Up");
	display(w, (t_xy){45, 200}, 0xFFFFFF, " - Go Down");
	display(w, (t_xy){20, 230}, 0xFFFFFF, " - Color white");
	display(w, (t_xy){20, 250}, 0xFFFFFF, " - Color Yellow");
	display(w, (t_xy){20, 270}, 0xFFFFFF, " - Color Red");
	display(w, (t_xy){20, 290}, 0xFFFFFF, " - Color Green");
	display(w, (t_xy){20, 310}, 0xFFFFFF, " - Color Blue");
	display(w, (t_xy){20, 330}, 0xFFFFFF, " - Color Pink");
	display(w, (t_xy){20, 350}, 0xFFFFFF, " - Color Cyan");
	display(w, (t_xy){20, 380}, 0xFFFFFF, " - Previous menu");	
}
