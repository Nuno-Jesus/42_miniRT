/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:58:12 by maricard          #+#    #+#             */
/*   Updated: 2023/09/04 10:58:01 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

t_menu_state	handle_light_changes(int keycode, t_world *w)
{
	t_light	*l;

	l = (t_light *)nc_vector_at(w->lights, w->menu.id);
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
		return (handle_light_color_changes(keycode, w, l));
	multithread(w);
	display_light_commands(w, w->menu.id);
	return (CHANGE_LIGHT);
}

t_menu_state	handle_light_color_changes(int keycode, t_world *w, t_light *l)
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
