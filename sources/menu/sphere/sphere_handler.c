/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:17:21 by maricard          #+#    #+#             */
/*   Updated: 2023/09/04 14:47:05 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_menu_state	handle_sphere_choice(int keycode, t_world *w)
{
	if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else if (keycode >= ONE && keycode <= NINE)
		return (display_sphere_commands(w, keycode - ONE), CHANGE_SPHERE);
	return (CHOOSE_SPHERE);
}

t_menu_state	handle_sphere_changes(int keycode, t_world *w)
{
	t_sphere	*sp;
	int			id;

	id = w->menu.ids[w->menu.id];
	sp = &((t_shape *)nc_vector_at(w->shapes, id))->data.sp;
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
		return (handle_sphere_size_change(keycode, w, sp));
	multithread(w);
	display_sphere_commands(w, w->menu.id);
	return (CHANGE_SPHERE);
}

t_menu_state	handle_sphere_size_change(int keycode, t_world *w, t_sphere *sp)
{
	if (keycode == LEFT)
		sp->radius += LEN;
	else if (keycode == RIGHT)
		sp->radius -= LEN;
	else
		return (handle_sphere_color_change(keycode, w, sp));
	multithread(w);
	display_sphere_commands(w, w->menu.id);
	return (CHANGE_SPHERE);
}

t_menu_state	handle_sphere_color_change(int keycode, t_world *w,
		t_sphere *sp)
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
	else if (keycode == SIX)
		sp->color = PINK;
	else if (keycode == SEVEN)
		sp->color = CYAN;
	else if (keycode == Q)
		return (display_sphere_choice_menu(w), CHOOSE_SPHERE);
	else
		return (CHANGE_SPHERE);
	multithread(w);
	display_sphere_commands(w, w->menu.id);
	return (CHANGE_SPHERE);
}
