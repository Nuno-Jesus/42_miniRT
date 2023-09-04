/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:15:14 by crypto            #+#    #+#             */
/*   Updated: 2023/09/04 16:15:25 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	get_uv(t_mesh *d, t_vec3 point, double *u, double *v)
{
	if (d->pl.normal.x != 0 + EPSILON)
	{
		*u = point.z;
		*v = point.y;
	}
	else if (d->pl.normal.y != 0 + EPSILON)
	{
		*u = point.x;
		*v = point.z;
	}
	else if (d->pl.normal.z != 0 + EPSILON)
	{
		*u = point.x;
		*v = point.y;
	}
	else
	{
		*u = 0.0;
		*v = 0.0;
	}
}

void	apply_texture(t_hit *closest)
{
	t_vec3	point;
	double	u;
	double	v;

	if (!closest->shape->is_textured)
		return ;
	point = closest->point;
	get_uv(&closest->shape->data, point, &u, &v);
	if ((int)(floor(u) + floor(v)) % 2)
		closest->color = BLACK;
	else
		closest->color = WHITE;
}
