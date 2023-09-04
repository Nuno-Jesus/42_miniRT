/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:17:21 by maricard          #+#    #+#             */
/*   Updated: 2023/09/04 10:58:42 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_menu_state	handle_plane_choice(int keycode, t_world *w)
{
	if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else if (keycode >= ONE && keycode <= NINE)
		return (display_plane_commands(w, keycode - ONE), CHANGE_PLANE);
	return (CHOOSE_PLANE);
}

t_menu_state	handle_plane_changes(int keycode, t_world *w)
{
	t_plane	*pl;
	int		id;

	id = w->menu.ids[w->menu.id];
	pl = &((t_shape *)nc_vector_at(w->shapes, id))->data.pl;
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
		return (handle_plane_color_changes(keycode, w, pl));
	multithread(w);
	display_plane_commands(w, w->menu.id);
	return (CHANGE_PLANE);
}

t_menu_state	handle_plane_color_changes(int keycode, t_world *w, t_plane *pl)
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
	else if (keycode == SIX)
		pl->color = PINK;
	else if (keycode == SEVEN)
		pl->color = CYAN;
	else if (keycode == Q)
		return (display_plane_choice_menu(w), CHOOSE_PLANE);
	else
		return (CHANGE_PLANE);
	multithread(w);
	display_plane_commands(w, w->menu.id);
	return (CHANGE_PLANE);
}
