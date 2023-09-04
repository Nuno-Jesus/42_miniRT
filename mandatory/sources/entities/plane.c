/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:05:09 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/14 16:56:17 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	plane_from_strings(t_plane *plane, char **tokens)
{
	char	**c;
	char	**n;
	char	**cl;

	c = nc_split(tokens[1], ',');
	n = nc_split(tokens[2], ',');
	cl = nc_split(tokens[3], ',');
	*plane = (t_plane)
	{
		.center = vec3_from_strings(c),
		.normal = vec3_from_strings(n),
		.color = color_from_strings(cl),
	};
	if (vec3_length(plane->normal) < 1.0 - EPSILON)
		return (false);
	plane->normal = vec3_normalize(plane->normal);
	plane->normal = vec3_add(plane->normal, VEC_EPSILON);
	nc_matrix_delete(c, &free);
	nc_matrix_delete(n, &free);
	nc_matrix_delete(cl, &free);
	return (true);
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
