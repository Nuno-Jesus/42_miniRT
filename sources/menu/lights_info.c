/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:58:12 by maricard          #+#    #+#             */
/*   Updated: 2023/08/31 16:42:57 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	light_info1(t_world *w)
{
	display(w, (t_xy){10, 90}, 0xFFFF00, "W");
	display(w, (t_xy){10, 110}, 0xFFFF00, "S");
	display(w, (t_xy){10, 130}, 0xFFFF00, "A");
	display(w, (t_xy){10, 150}, 0xFFFF00, "D");
	display(w, (t_xy){10, 180}, 0xFFFF00, "UP");
	display(w, (t_xy){10, 200}, 0xFFFF00, "DOWN");
	display(w, (t_xy){10, 220}, 0xFFFF00, "LEFT");
	display(w, (t_xy){10, 240}, 0xFFFF00, "RIGHT");
	display(w, (t_xy){10, 270}, 0xFFFF00, "1");
	display(w, (t_xy){10, 290}, 0xFFFF00, "2");
	display(w, (t_xy){10, 310}, 0xFFFF00, "3");
	display(w, (t_xy){10, 330}, 0xFFFF00, "4");
	display(w, (t_xy){10, 350}, 0xFFFF00, "5");
	display(w, (t_xy){10, 370}, 0xFFFF00, "6");
	display(w, (t_xy){10, 390}, 0xFFFF00, "7");
	display(w, (t_xy){10, 420}, 0xFF0000, "Q");
}

void	light_info2(t_world *w)
{
	display(w, (t_xy){20, 90}, 0xFFFFFF, " - Move Foward");
	display(w, (t_xy){20, 110}, 0xFFFFFF, " - Move Backwards");
	display(w, (t_xy){20, 130}, 0xFFFFFF, " - Move Left");
	display(w, (t_xy){20, 150}, 0xFFFFFF, " - Move Right");
	display(w, (t_xy){25, 180}, 0xFFFFFF, " - Go Up");
	display(w, (t_xy){45, 200}, 0xFFFFFF, " - Go Down");
	display(w, (t_xy){45, 220}, 0xFFFFFF, " - Increase ratio");
	display(w, (t_xy){50, 240}, 0xFFFFFF, " - Decrease ratio");
	display(w, (t_xy){20, 270}, 0xFFFFFF, " - Color white");
	display(w, (t_xy){20, 290}, 0xFFFFFF, " - Color Yellow");
	display(w, (t_xy){20, 310}, 0xFFFFFF, " - Color Red");
	display(w, (t_xy){20, 330}, 0xFFFFFF, " - Color Green");
	display(w, (t_xy){20, 350}, 0xFFFFFF, " - Color Blue");
	display(w, (t_xy){20, 370}, 0xFFFFFF, " - Color Pink");
	display(w, (t_xy){20, 390}, 0xFFFFFF, " - Color Cyan");
	display(w, (t_xy){20, 420}, 0xFFFFFF, " - Previous menu");	
}

t_menu_state	handle_light_changes_2(int keycode, t_world *w, t_light *l)
{
	if (keycode == ONE)
		l->color = WHITE;
	else if (keycode == TWO)
		l->color = YELLOW;
	else if (keycode == THREE)
		l->color = RED;
	else if (keycode == FOUR)
		l->color = GREEN;
	else if (keycode == FIVE)
		l->color = BLUE;
	else if (keycode == SIX)
		l->color = PINK;
	else if (keycode == SEVEN)
		l->color = CYAN;
	else if (keycode == Q)
		return (display_light_choice_menu(w), CHOOSE_LIGHT);
	else
		return (CHANGE_LIGHT);
	multithread(w);
	display_light_commands(w, w->menu.id);
	return (CHANGE_LIGHT);
}

t_menu_state	handle_light_changes(int keycode, t_world *w)
{
	t_light	*l;

	l = (t_light*)nc_vector_at(w->lights, w->menu.id);
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
	else if (keycode == RIGHT)
		l->ratio -= 0.1;
	else
		return (handle_light_changes_2(keycode, w, l));
	multithread(w);
	display_light_commands(w, w->menu.id);
	return (CHANGE_LIGHT);
}
