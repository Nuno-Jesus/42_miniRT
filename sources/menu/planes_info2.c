/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes_info2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:17:21 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 15:33:00 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		move_plane_color(int keycode, t_world *w, t_plane *pl)
{
	if (keycode == ONE)
		pl->color = WHITE;
	else if (keycode == TWO)
		pl->color = YELLOW;
	else if (keycode == THREE)
		pl->color = RED;
	else if (keycode == FOUR)
		pl->color = GREEN;
	else if (keycode == FIVE)
		pl->color = BLUE;
	else if (keycode == Q)
	{
		handle_plane_choice(w);
		return (keycode);
	}
	else if (keycode == ESC)
		quit(w);
	else
		return (keycode);
	multithread(w);
	plane(w, w->menu.id);
	return (keycode);
}

int		move_plane(int keycode, t_world *w)
{
	t_plane	*pl;
	int			id;

	id = w->menu.ids[w->menu.id];
	pl = &((t_shape*)nc_vector_at(w->shapes, id))->data.pl;
	if (keycode == W)
		pl->center.z += MOVE;
	else if (keycode == S)
		pl->center.z -= MOVE;
	else if (keycode == A)
		pl->center.x -= MOVE;
	else if (keycode == D)
		pl->center.x += MOVE;
	else if (keycode == UP)
		pl->center.y += MOVE;
	else if (keycode == DOWN)
		pl->center.y -= MOVE;
	else
	{
		keycode = move_plane_color(keycode, w, pl);
		return (keycode);
	}
	multithread(w);
	plane(w, w->menu.id);
	return (keycode);
}
