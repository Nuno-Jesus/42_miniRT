/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:05:09 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/12 16:19:13 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_plane	plane_from_strings(char **tokens)
{
	char	**c;
	char	**n;
	char	**cl;
	t_plane	plane;

	c = nc_split(tokens[1], ',');
	n = nc_split(tokens[2], ',');
	cl = nc_split(tokens[3], ',');
	plane = (t_plane)
	{
		.center = vec3_new(nc_atod(c[X]), nc_atod(c[Y]), nc_atod(c[Z])), 
		.normal = vec3_new(nc_atod(n[X]), nc_atod(n[Y]), nc_atod(n[Z])), 
		.color = color_new(nc_atod(cl[R]), nc_atod(cl[G]), nc_atod(cl[B])),
	};
	plane.normal = vec3_normalize(plane.normal);
	plane.normal = vec3_add(plane.normal, VEC_EPSILON);
	nc_matrix_delete(c, &free);
	nc_matrix_delete(n, &free);
	nc_matrix_delete(cl, &free);
	return (plane);
}

t_plane	plane_from_numbers(t_vec3 center, t_vec3 normal, t_color color)
{
	t_plane	plane;

	plane = (t_plane)
	{
		.center = center,
		.normal = normal,
		.color = color
	};
	return (plane);
}

bool	plane_intersect(t_plane *pl, t_ray *ray, t_hit *inter)
{
	t_vec3		co;
	t_equation	equation;

	if (vec3_dot(ray->direction, pl->normal) != 0.0)
	{
		co = vec3_sub(ray->origin, pl->center);
		equation.a = 0;
		equation.b = vec3_dot(ray->direction, pl->normal);
		equation.c = vec3_dot(co, pl->normal);
		solve(&equation);
		if (equation.t1 > EPSILON)
		{
			inter->t = equation.t1;
			inter->color = pl->color;
			return (true);
		}
	}
	return (false);
}
