/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:18:51 by maricard          #+#    #+#             */
/*   Updated: 2023/08/15 15:27:34 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	torus_from_strings(t_torus *to, char **tokens)
{
	char		**c;
	char		**n;
	char		**cl;

	c = nc_split(tokens[1], ',');
	n = nc_split(tokens[2], ',');
	cl = nc_split(tokens[5], ',');
	*to = (t_torus)
	{
		.r1 = nc_atod(tokens[3]) / 2.0,
		.r2 = nc_atod(tokens[4]) / 2.0,
		.center = vec3_from_strings(c),
		.normal = vec3_from_strings(n),
		.color = color_from_strings(cl),
	};
	nc_matrix_delete(c, &free);
	nc_matrix_delete(n, &free);
	nc_matrix_delete(cl, &free);
	if (vec3_length(to->normal) < 1.0 - EPSILON \
		|| to->r1 < EPSILON || to->r2 < EPSILON || to->r1 <= to->r2)
		return (false);
	to->normal = vec3_normalize(to->normal);
	return (true);
}