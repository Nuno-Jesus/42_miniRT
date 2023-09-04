/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:52:06 by maricard          #+#    #+#             */
/*   Updated: 2023/09/04 13:25:32 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	search_for_spheres(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	init_flags(w);
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type == SPHERE && w->menu.sp_flag == 0)
		{
			w->menu.sp_flag = 1;
			display(w, (t_xy){5, 125 + (++w->menu.i * 20)}, 0xFFFF00, "4");
			display(w, (t_xy){25, 125 + (w->menu.i * 20)}, 0xFFFFFF,
				"- SPHERE");
		}
	}
}

void	search_for_planes(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	init_flags(w);
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type == PLANE && w->menu.sp_flag == 0)
		{
			w->menu.sp_flag = 1;
			display(w, (t_xy){5, 125 + (++w->menu.i * 20)}, 0xFFFF00, "5");
			display(w, (t_xy){25, 125 + (w->menu.i * 20)}, 0xFFFFFF, "- PLANE");
		}
	}
}

void	search_for_cylinders(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	init_flags(w);
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type == CYLINDER && w->menu.sp_flag == 0)
		{
			w->menu.sp_flag = 1;
			display(w, (t_xy){5, 125 + (++w->menu.i * 20)}, 0xFFFF00, "6");
			display(w, (t_xy){25, 125 + (w->menu.i * 20)}, 0xFFFFFF,
				"- CYLINDER");
		}
	}
}

void	search_for_cones(t_world *w)
{
	uint32_t	i;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	init_flags(w);
	while (++i < w->shapes->size)
	{
		shape = nc_vector_at(w->shapes, i);
		if (shape->type == CONE && w->menu.sp_flag == 0)
		{
			w->menu.sp_flag = 1;
			display(w, (t_xy){5, 125 + (++w->menu.i * 20)}, 0xFFFF00, "7");
			display(w, (t_xy){25, 125 + (w->menu.i * 20)}, 0xFFFFFF, "- CONE");
		}
	}
}

void	search_shapes(t_world *w)
{
	search_for_spheres(w);
	search_for_planes(w);
	search_for_cylinders(w);
	search_for_cones(w);
}
