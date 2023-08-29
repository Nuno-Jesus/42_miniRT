/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres_info2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:17:21 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 15:32:45 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		move_sphere_color(int keycode, t_world *w, t_sphere *sp)
{
	if (keycode == ONE)
		sp->color = WHITE;
	else if (keycode == TWO)
		sp->color = YELLOW;
	else if (keycode == THREE)
		sp->color = RED;
	else if (keycode == FOUR)
		sp->color = GREEN;
	else if (keycode == FIVE)
		sp->color = BLUE;
	else if (keycode == Q)
	{
		handle_sphere_choice(w);
		return (keycode);
	}
	else if (keycode == ESC)
		quit(w);
	else
		return (keycode);
	multithread(w);
	sphere(w, w->menu.id);
	return (keycode);
}

int		move_sphere2(int keycode, t_world *w, t_sphere *sp)
{
	if (keycode == LEFT)
		sp->radius += LEN;
	else if (keycode == RIGHT)
		sp->radius -= LEN;
	else
	{
		keycode = move_sphere_color(keycode, w, sp);
		return (keycode);
	}
	multithread(w);
	sphere(w, w->menu.id);
	return (keycode);
}

int		move_sphere(int keycode, t_world *w)
{
	t_sphere	*sp;
	int			id;

	id = w->menu.ids[w->menu.id];
	sp = &((t_shape*)nc_vector_at(w->shapes, id))->data.sp;
	if (keycode == W)
		sp->center.z += MOVE;
	else if (keycode == S)
		sp->center.z -= MOVE;
	else if (keycode == A)
		sp->center.x -= MOVE;
	else if (keycode == D)
		sp->center.x += MOVE;
	else if (keycode == UP)
		sp->center.y += MOVE;
	else if (keycode == DOWN)
		sp->center.y -= MOVE;
	else
	{
		keycode = move_sphere2(keycode, w, sp);
		return (keycode);
	}
	multithread(w);
	sphere(w, w->menu.id);
	return (keycode);
}