/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/04 16:31:11 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_plane		*plane_new(char **point, char **normal, char **color)
{
	t_plane	*plane;

	plane = nc_calloc(1, sizeof(t_plane));
	if (!plane)
		return (NULL);
	*plane = (t_plane)
	{
		.point.x = nc_atof(point[0]),
		.point.y = nc_atof(point[1]),
		.point.z = nc_atof(point[2]),
		.normal.x = nc_atof(normal[0]),
		.normal.y = nc_atof(normal[1]),
		.normal.z = nc_atof(normal[2]),
		.color.r = nc_atoi(color[0]),
		.color.g = nc_atoi(color[1]),
		.color.b = nc_atoi(color[2]),
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

void	plane_print(t_plane *p)
{
	printf("Plane:\n");
	printf("  Point: %.2f, %.2f, %.2f\n", p->point.x, p->point.y, p->point.z);
	printf("  Normal: %.2f, %.2f, %.2f\n", p->normal.x, p->normal.y, p->normal.z);
	printf("  Color: (%d, %d, %d)\n", p->color.r, p->color.g, p->color.b);
}