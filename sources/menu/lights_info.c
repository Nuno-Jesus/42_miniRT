/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:58:12 by maricard          #+#    #+#             */
/*   Updated: 2023/08/23 16:00:36 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	light_info1(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 90, 0xFFFF00, "W");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 110, 0xFFFF00, "S");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 130, 0xFFFF00, "A");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 150, 0xFFFF00, "D");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 180, 0xFFFF00, "UP");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 200, 0xFFFF00, "DOWN");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 220, 0xFFFF00, "LEFT");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 240, 0xFFFF00, "RIGHT");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 270, 0xFFFF00, "1");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 290, 0xFFFF00, "2");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 310, 0xFFFF00, "3");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 330, 0xFFFF00, "4");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 350, 0xFFFF00, "5");
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 380, 0xFF0000, "Q");
}

void	light_info2(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 90, \
		0xFFFFFF, " - Move Foward");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 110, \
		0xFFFFFF, " - Move Backwards");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 130, \
		0xFFFFFF, " - Move Left");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 150, \
		0xFFFFFF, " - Move Right");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, 180, \
		0xFFFFFF, " - Go Up");
	mlx_string_put(w->disp.mlx, w->disp.win, 45, 200, \
		0xFFFFFF, " - Go Down");
	mlx_string_put(w->disp.mlx, w->disp.win, 45, 220, \
		0xFFFFFF, " - Increase ratio");
	mlx_string_put(w->disp.mlx, w->disp.win, 50, 240, \
		0xFFFFFF, " - Decrease ratio");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 270, \
		0xFFFFFF, " - Color white");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 290, \
		0xFFFFFF, " - Color Yellow");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 310, \
		0xFFFFFF, " - Color Red");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 330, \
		0xFFFFFF, " - Color Green");
}

void	light_info3(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 350, \
		0xFFFFFF, " - Color Blue");
	mlx_string_put(w->disp.mlx, w->disp.win, 20, 380, \
		0xFFFFFF, " - Previous menu");		
}

int		move_light2(int keycode, t_world *w, t_light *l)
{
	if (keycode == RIGHT)
		l->ratio -= 0.1;
	else if (keycode == ONE)
		l->color = WHITE;
	else if (keycode == TWO)
		l->color = YELLOW;
	else if (keycode == THREE)
		l->color = RED;
	else if (keycode == FOUR)
		l->color = GREEN;
	else if (keycode == FIVE)
		l->color = BLUE;
	else if (keycode == Q)
	{
		change_light(w);
		return (keycode);
	}
	else if (keycode == ESC)
		quit(w);
	else
		return (keycode);
	multithread(w);
	light(w, w->menu.id);
	return (keycode);
}

int		move_light(int keycode, t_world *w)
{
	t_light	*l;

	l = nc_vector_at(w->lights, w->menu.id);
	if (keycode == W)
		l->center.z += MOVE;
	else if (keycode == S)
		l->center.z -= MOVE;
	else if (keycode == A)
		l->center.x -= MOVE;
	else if (keycode == D)
		l->center.x += MOVE;
	else if (keycode == UP)
		l->center.y += MOVE;
	else if (keycode == DOWN)
		l->center.y -= MOVE;
	else if (keycode == LEFT)
		l->ratio += 0.1;
	else
	{
		keycode = move_light2(keycode, w, l);
		return (keycode);
	}
	multithread(w);
	light(w, w->menu.id);
	return (keycode);
}
