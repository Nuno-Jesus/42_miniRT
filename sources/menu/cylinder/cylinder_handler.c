/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders_info2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:28:51 by maricard          #+#    #+#             */
/*   Updated: 2023/08/31 17:56:36 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_menu_state	handle_cylinder_choice(int keycode, t_world *w)
{
	if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else if (keycode >= ONE && keycode <= NINE)
		return (display_cylinder_commands(w, keycode - ONE), CHANGE_CYLINDER);
	return (CHOOSE_CYLINDER);
}

t_menu_state	handle_cylinder_changes(int keycode, t_world *w)
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
		return (handle_cylinder_size_changes(keycode, w, cy));
	multithread(w);
	display_cylinder_commands(w, w->menu.id);
	return (CHANGE_CYLINDER);
}

t_menu_state	handle_cylinder_size_changes(int keycode, t_world *w, t_cylinder *cy)
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
		return(handle_cylinder_color_changes(keycode, w, cy));
	multithread(w);
	display_cylinder_commands(w, w->menu.id);
	return (CHANGE_CYLINDER);
}

t_menu_state	handle_cylinder_color_changes(int keycode, t_world *w, t_cylinder *cy)
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
	else if (keycode == SIX)
		cy->color = PINK;
	else if (keycode == SEVEN)
		cy->color = CYAN;
	else if (keycode == Q)
		return (display_cylinder_choice_menu(w), CHOOSE_CYLINDER);
	else
		return (CHANGE_CYLINDER);
	multithread(w);
	display_cylinder_commands(w, w->menu.id);
	return (CHANGE_CYLINDER);
}

