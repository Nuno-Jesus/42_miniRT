/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders_info2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:28:51 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 12:46:04 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		move_cylinder_color(int keycode, t_world *w, t_cylinder *cy)
{
	if (keycode == ONE)
		cy->color = WHITE;
	else if (keycode == TWO)
		cy->color = YELLOW;
	else if (keycode == THREE)
		cy->color = RED;
	else if (keycode == FOUR)
		cy->color = GREEN;
	else if (keycode == FIVE)
		cy->color = BLUE;
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

int		move_cylinder2(int keycode, t_world *w, t_cylinder *cy)
{
	if (keycode == LEFT)
		cy->radius += LEN;
	else if (keycode == RIGHT)
		cy->radius -= LEN; 
	else if (keycode == C)
		cy->height += LEN;
	else if (keycode == V)
		cy->height -= LEN; 
	else
	{
		move_cylinder_color(keycode, w, cy);
		return (keycode);
	}
	multithread(w);
	cylinder(w, w->menu.id);
	return (keycode);
}

int		move_cylinder(int keycode, t_world *w)
{
	t_cylinder	*cy;
	int			id;

	id = w->menu.ids[w->menu.id];
	cy = &((t_shape*)nc_vector_at(w->shapes, id))->data.cy;
	if (keycode == W)
		cy->center.z += MOVE;
	else if (keycode == S)
		cy->center.z -= MOVE;
	else if (keycode == A)
		cy->center.x -= MOVE;
	else if (keycode == D)
		cy->center.x += MOVE;
	else if (keycode == UP)
		cy->center.y += MOVE;
	else if (keycode == DOWN)
		cy->center.y -= MOVE;
	else
	{
		keycode = move_cylinder2(keycode, w, cy);
		return (keycode);
	}
	multithread(w);
	cylinder(w, w->menu.id);
	return (keycode);
}