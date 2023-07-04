/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/04 16:31:11 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cylinder	*cylinder_new(char **center, char **normal, char *radius, char *height, char **color)
{
	t_cylinder	*cy;

	cy = nc_calloc(1, sizeof(t_cylinder));
	if (!cy)
		return (NULL);
	*cy = (t_cylinder)
	{
		.center.x = nc_atof(center[0]),
		.center.y = nc_atof(center[1]),
		.center.z = nc_atof(center[2]),
		.normal.x = nc_atof(normal[0]),
		.normal.y = nc_atof(normal[1]),
		.normal.z = nc_atof(normal[2]),
		.radius = nc_atof(radius),
		.height = nc_atof(height),
		.color.r = nc_atoi(color[0]),
		.color.g = nc_atoi(color[1]),
		.color.b = nc_atoi(color[2]),
	};
	return (cy);
}

t_cylinder	*cylinder_copy(t_cylinder *cylinder)
{
	t_cylinder	*copy;

	copy = nc_calloc(1, sizeof(t_cylinder));
	if (!copy)
		return (NULL);
	*copy = *cylinder;
	return (copy);
}

void	cylinder_print(t_cylinder *c)
{
	printf("Cylinder:\n");
	printf("  Center: (%.2f, %.2f, %.2f)\n", c->center.x, c->center.y, c->center.z);
	printf("  Normal: (%.2f, %.2f, %.2f)\n", c->normal.x, c->normal.y, c->normal.z);
	printf("  Radius: %.2f\n", c->radius);
	printf("  Height: %.2f\n", c->height);
	printf("  Color: (%d, %d, %d)\n", c->color.r, c->color.g, c->color.b);
}
