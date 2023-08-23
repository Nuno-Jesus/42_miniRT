/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders_info2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:28:51 by maricard          #+#    #+#             */
/*   Updated: 2023/08/23 18:46:55 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		move_cylinder_color(int keycode, t_world *w, t_cylinder *s)
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
		change_cylinder(w);
		return (keycode);
	}
	else if (keycode == ESC)
		quit(w);
	else
		return (keycode);
	multithread(w);
	cylinder(w, w->menu.id);
	return (keycode);
}

int		move_cylinder2(int keycode, t_world *w, t_cylinder *s)
{
	if (keycode == LEFT)
		s->radius += MOVE;
	else if (keycode == RIGHT)
		s->radius -= MOVE; 
	else if (keycode == C)
		s->height += MOVE;
	else if (keycode == V)
		s->height -= MOVE; 
	else if (keycode == Q)
	{
		move_cylinder_color(keycode, w, s);
		return (keycode);
	}
	multithread(w);
	cylinder(w, w->menu.id);
	return (keycode);
}

int		move_cylinder(int keycode, t_world *w)
{
	t_cylinder	*c;
	int			id;

	id = w->menu.ids[w->menu.id];
	c = nc_vector_at(w->shapes, id);
	if (keycode == W)
		c->center.z += MOVE;
	else if (keycode == S)
		c->center.z -= MOVE;
	else if (keycode == A)
		c->center.x -= MOVE;
	else if (keycode == D)
		c->center.x += MOVE;
	else if (keycode == UP)
		c->center.y += MOVE;
	else if (keycode == DOWN)
		c->center.y -= MOVE;
	else
	{
		keycode = move_cylinder2(keycode, w,c);
		return (keycode);
	}
	multithread(w);
	cylinder(w, w->menu.id);
	return (keycode);
}