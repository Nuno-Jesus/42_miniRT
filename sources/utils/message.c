/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:30:28 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/31 15:52:15 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	message(t_world *world, char *text)
{
	destroy_world(&world);
	if (text)
		ERROR(text);
	exit(EXIT_FAILURE);
}

void	display(t_world *w, t_xy xy, int color, char *text)
{
	mlx_string_put(w->disp.mlx, w->disp.win, xy.x, xy.y, color, text);
}
