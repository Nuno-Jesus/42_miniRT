/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:50:10 by maricard          #+#    #+#             */
/*   Updated: 2023/08/22 21:55:30 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_flags(t_world *w)
{
	w->helper.sp_flag = 0;
	w->helper.pl_flag = 0;
	w->helper.cy_flag = 0;
	w->helper.co_flag = 0;
	w->helper.i = -1;
}

void	write_shapes(t_world *w)
{
	mlx_string_put(w->disp.mlx, w->disp.win, 10, 53, \
		0xFFFFFF, "LIST OF OBJECTS");
	mlx_string_put(w->disp.mlx, w->disp.win, 6, 64, \
		0xFFA160, "----------------");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, 85, 0xFFFF00, "1");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, 105, 0xFFFF00, "2");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, 125, 0xFFFF00, "3");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, 85, \
		0xFFFFFF, "- CAMERA");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, 105, \
		0xFFFFFF, "- AMBIENT LIGHT");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, 125, \
		0xFFFFFF, "- LIGHTS");
	search_shapes(w, w->shapes);
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		145 + (++w->helper.i * 20 + 15), 0xFFFF00, "FOR MORE INFO");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		145 + (w->helper.i * 20 + 35), 0xFFFF00, "PRESS A NUMBER");
	mlx_string_put(w->disp.mlx, w->disp.win, 5, \
		145 + (++w->helper.i * 20 + 50), 0xFFFF00, "Q");
	mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			145 + (w->helper.i * 20 + 50), 0xFFFFFF, "- Quit Menu");
}

void	write_shapes_info(t_world *w, t_shape *shape)
{
	if (shape->type == SPHERE &&w->helper.sp_flag == 0)
	{
		w->helper.sp_flag = 1;
		mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			145 + (++w->helper.i * 20), 0xFFFFFF, "- SPHERE");
	}
	else if (shape->type == PLANE && w->helper.pl_flag == 0)
	{
		w->helper.pl_flag = 1;
		mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			145 + (++w->helper.i * 20), 0xFFFFFF, "- PLANE");
	}
	else if (shape->type == CYLINDER && w->helper.cy_flag == 0)
	{
		w->helper.cy_flag = 1;
		mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			145 + (++w->helper.i * 20), 0xFFFFFF, "- CYLINDER");
	}
	else if (shape->type == CONE && w->helper.co_flag == 0)
	{
		w->helper.co_flag = 1;
		mlx_string_put(w->disp.mlx, w->disp.win, 25, \
			145 + (++w->helper.i * 20), 0xFFFFFF, "- CONE");
	}
}

void	search_shapes_id(t_world *w, t_shape *shape, uint32_t *j)
{
	if (shape->type == SPHERE && w->helper.sp_flag == 0)
	{
		w->helper.sp_flag = 1;
		mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			145 + (++w->helper.i * 20), 0xFFFF00, nc_itoa(++*j));
	}
	else if (shape->type == PLANE && w->helper.pl_flag == 0)
	{
		w->helper.pl_flag = 1;
		mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			145 + (++w->helper.i * 20), 0xFFFF00, nc_itoa(++*j));
	}
	else if (shape->type == CYLINDER && w->helper.cy_flag == 0)
	{
		w->helper.cy_flag = 1;
		mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			145 + (++w->helper.i * 20), 0xFFFF00, nc_itoa(++*j));
	}
	else if (shape->type == CONE && w->helper.co_flag == 0)
	{
		w->helper.co_flag = 1;
		mlx_string_put(w->disp.mlx, w->disp.win, 5, \
			145 + (++w->helper.i * 20), 0xFFFF00, nc_itoa(++*j));
	}
}

void	search_shapes(t_world *w, t_vector *s)
{
	uint32_t	i;
	uint32_t	j;
	t_shape		*shape;

	i = -1;
	shape = NULL;
	j = 3;
	init_flags(w);
	while (++i < s->size)
	{
		shape = nc_vector_at(s, i);
		search_shapes_id(w, shape, &j);
	}
	i = -1;
	init_flags(w);
	while (++i < s->size)
	{
		shape = nc_vector_at(s, i);
		write_shapes_info(w, shape);
	}
}
