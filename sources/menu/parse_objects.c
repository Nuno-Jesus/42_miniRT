/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:52:06 by maricard          #+#    #+#             */
/*   Updated: 2023/08/23 19:53:57 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check_for_spheres(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	init_flags(w);
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type == SPHERE &&w->menu.sp_flag == 0)
		{
			w->menu.sp_flag = 1;
			mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			125 + (++w->menu.i * 20), 0xFFFF00, nc_itoa(4));
			mlx_string_put(w->disp.mlx, w->disp.win, 25, \
				125 + (w->menu.i * 20), 0xFFFFFF, "- SPHERE");
		}
	}
}

void	check_for_planes(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	init_flags(w);
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type == PLANE &&w->menu.sp_flag == 0)
		{
			w->menu.sp_flag = 1;
			mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			125 + (++w->menu.i * 20), 0xFFFF00, nc_itoa(5));
			mlx_string_put(w->disp.mlx, w->disp.win, 25, \
				125 + (w->menu.i * 20), 0xFFFFFF, "- PLANE");
		}
	}
}

void	check_for_cylinders(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	init_flags(w);
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type == CYLINDER &&w->menu.sp_flag == 0)
		{
			w->menu.sp_flag = 1;
			mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			125 + (++w->menu.i * 20), 0xFFFF00, nc_itoa(6));
			mlx_string_put(w->disp.mlx, w->disp.win, 25, \
				125 + (w->menu.i * 20), 0xFFFFFF, "- CYLINDER");
		}
	}
}

void	check_for_cones(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	init_flags(w);
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type == CONE &&w->menu.sp_flag == 0)
		{
			w->menu.sp_flag = 1;
			mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			125 + (++w->menu.i * 20), 0xFFFF00, nc_itoa(7));
			mlx_string_put(w->disp.mlx, w->disp.win, 25, \
				125 + (w->menu.i * 20), 0xFFFFFF, "- CONE");
		}
	}
}

void	search_shapes(t_world *w)
{
	check_for_spheres(w);
	check_for_planes(w);
	check_for_cylinders(w);
	check_for_cones(w);
}
