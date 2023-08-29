/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cones_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:28:51 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 15:33:25 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		move_cone_color(int keycode, t_world *w, t_cone *co)
{
	if (keycode == ONE)
		co->color = WHITE;
	else if (keycode == TWO)
		co->color = YELLOW;
	else if (keycode == THREE)
		co->color = RED;
	else if (keycode == FOUR)
		co->color = GREEN;
	else if (keycode == FIVE)
		co->color = BLUE;
	else if (keycode == Q)
	{
		handle_cone_choice(w);
		return (keycode);
	}
	else if (keycode == ESC)
		quit(w);
	else
		return (keycode);
	multithread(w);
	cone(w, w->menu.id);
	return (keycode);
}

int		move_cone2(int keycode, t_world *w, t_cone *co)
{
	if (keycode == LEFT)
		co->radius += LEN;
	else if (keycode == RIGHT)
		co->radius -= LEN; 
	else if (keycode == C)
		co->height += LEN;
	else if (keycode == V)
		co->height -= LEN; 
	else
	{
		move_cone_color(keycode, w, co);
		return (keycode);
	}
	multithread(w);
	cone(w, w->menu.id);
	return (keycode);
}

int		move_cone(int keycode, t_world *w)
{
	t_cone	*co;
	int			id;

	id = w->menu.ids[w->menu.id];
	co = &((t_shape*)nc_vector_at(w->shapes, id))->data.co;
	if (keycode == W)
		co->tip.z += MOVE;
	else if (keycode == S)
		co->tip.z -= MOVE;
	else if (keycode == A)
		co->tip.x -= MOVE;
	else if (keycode == D)
		co->tip.x += MOVE;
	else if (keycode == UP)
		co->tip.y += MOVE;
	else if (keycode == DOWN)
		co->tip.y -= MOVE;
	else
	{
		keycode = move_cone2(keycode, w, co);
		return (keycode);
	}
	multithread(w);
	cone(w, w->menu.id);
	return (keycode);
}