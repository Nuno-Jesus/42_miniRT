/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:50:10 by maricard          #+#    #+#             */
/*   Updated: 2023/08/31 16:14:45 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_flags(t_world *w)
{
	w->menu.sp_flag = 0;
	w->menu.pl_flag = 0;
	w->menu.cy_flag = 0;
	w->menu.co_flag = 0;
}

void	display_menu_entites(t_world *w)
{
	display(w, (t_xy){10, 53}, 0xFFFFFF, "LIST OF OBJECTS");
	display(w, (t_xy){6, 64}, 0xFFA160, "----------------");
	display(w, (t_xy){5, 85}, 0xFFFF00, "1");
	display(w, (t_xy){5, 105}, 0xFFFF00, "2");
	display(w, (t_xy){5, 125}, 0xFFFF00, "3");
	display(w, (t_xy){25, 85}, 0xFFFFFF, "- CAMERA");
	display(w, (t_xy){25, 105}, 0xFFFFFF, "- AMBIENT LIGHT");
	display(w, (t_xy){25, 125}, 0xFFFFFF, "- LIGHTS");
	search_shapes(w);
	display(w, (t_xy){5, 145 + (++w->menu.i * 20 + 15)}, \
		0xFFFF00, "FOR MORE INFO");
	display(w, (t_xy){5, 145 + (w->menu.i * 20 + 35)}, \
		0xFFFF00, "PRESS A NUMBER");
	display(w, (t_xy){5, 145 + (++w->menu.i * 20 + 50)}, \
		0xFF0000, "Q");
	display(w, (t_xy){25, 145 + (w->menu.i * 20 + 50)}, \
		0xFFFFFF, "- Quit Menu");
}
