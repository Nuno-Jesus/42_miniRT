/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:56:47 by maricard          #+#    #+#             */
/*   Updated: 2023/08/31 17:50:31 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_menu_state	handle_amb_light_changes(int keycode, t_world *w)
{
	if (keycode == LEFT)
		w->ambient.ratio += 0.1;
	else if (keycode == RIGHT)
		w->ambient.ratio -= 0.1;
	else if (keycode == Q)
		return (display_main_menu(w), MENU_OPENED);
	else
		return (CHANGE_AMBIENT_LIGHT);
	multithread(w);
	display_amb_light_menu(w);
	return (CHANGE_AMBIENT_LIGHT);
}

void	display_amb_light_menu(t_world *w)
{
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.menu, 0, 0);
	display_menu_title(w);
	display(w, (t_xy){10, 53}, 0xFFFFFF, "AMBIENT LIGHT");
	display(w, (t_xy){9, 64}, 0xFFA160, "-------------");
	display(w, (t_xy){10, 90}, 0xFFFF00, "LEFT");
	display(w, (t_xy){10, 110}, 0xFFFF00, "RIGHT");
	display(w, (t_xy){10, 140}, 0xFF0000, "Q");
	display(w, (t_xy){45, 90}, 0xFFFFFF, " - Increase ratio");
	display(w, (t_xy){50, 110}, 0xFFFFFF, " - Decrease ratio");
	display(w, (t_xy){20, 140}, 0xFFFFFF, " - Previous menu");
}