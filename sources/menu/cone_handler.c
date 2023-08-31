/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:28:51 by maricard          #+#    #+#             */
/*   Updated: 2023/08/31 17:54:52 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_menu_state	handle_cone_choice(int keycode, t_world *w)
{
	if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else if (keycode >= ONE && keycode <= NINE)
		return (display_cone_commands(w, keycode - ONE), CHANGE_CONE);
	return (CHOOSE_CONE);
}

t_menu_state	handle_cone_changes(int keycode, t_world *w)
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
		return (handle_cone_size_changes(keycode, w, co));
	multithread(w);
	display_cylinder_commands(w, w->menu.id);
	return (CHANGE_CONE);
}

t_menu_state	handle_cone_size_changes(int keycode, t_world *w, t_cone *co)
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
		return (handle_cone_color_changes(keycode, w, co));
	multithread(w);
	display_cylinder_commands(w, w->menu.id);
	return (CHANGE_CONE);
}

t_menu_state	handle_cone_color_changes(int keycode, t_world *w, t_cone *co)
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
	else if (keycode == SIX)
		co->color = PINK;
	else if (keycode == SEVEN)
		co->color = CYAN;
	else if (keycode == Q)
		return (display_cone_choice_menu(w), CHOOSE_CONE);
	else
		return (CHANGE_CONE);
	multithread(w);
	display_cylinder_commands(w, w->menu.id);
	return (CHANGE_CONE);
}
