/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/05 11:35:03 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_plane	*plane_new(char **c, char **n, char **cl)
{
	t_plane	*plane;

	plane = nc_calloc(1, sizeof(t_plane));
	if (!plane)
		return (NULL);
	*plane = (t_plane)
	{
		.point = vec3_new(nc_atof(c[X]), nc_atof(c[Y]), nc_atof(c[Z])), 
		.normal = vec3_new(nc_atof(n[X]), nc_atof(n[Y]), nc_atof(n[Z])), 
		.color = color_new(nc_atof(cl[R]), nc_atof(cl[G]), nc_atof(cl[B])),
	};
	return (plane);
}

t_plane	*plane_copy(t_plane *plane)
{
	t_plane	*copy;

	copy = nc_calloc(1, sizeof(t_plane));
	if (!copy)
		return (NULL);
	*copy = *plane;
	return (copy);
}
