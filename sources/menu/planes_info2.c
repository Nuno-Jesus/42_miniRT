/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes_info2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:17:21 by maricard          #+#    #+#             */
/*   Updated: 2023/08/23 20:03:26 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		move_plane_color(int keycode, t_world *w, t_plane *s)
{
	if (keycode == ONE)
		s->color = WHITE;
	else if (keycode == TWO)
		s->color = YELLOW;
	else if (keycode == THREE)
		s->color = RED;
	else if (keycode == FOUR)
		s->color = GREEN;
	else if (keycode == FIVE)
		s->color = BLUE;
	else if (keycode == Q)
	{
		change_plane(w);
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
	t_plane	*s;
	int			id;

	id = w->menu.ids[w->menu.id];
	s = nc_vector_at(w->shapes, id);
	if (keycode == W)
		s->center.z += MOVE;
	else if (keycode == S)
		s->center.z -= MOVE;
	else if (keycode == A)
		s->center.x -= MOVE;
	else if (keycode == D)
		s->center.x += MOVE;
	else if (keycode == UP)
		s->center.y += MOVE;
	else if (keycode == DOWN)
		s->center.y -= MOVE;
	else
	{
		keycode = move_plane_color(keycode, w, s);
		return (keycode);
	}
	multithread(w);
	plane(w, w->menu.id);
	return (keycode);
}
