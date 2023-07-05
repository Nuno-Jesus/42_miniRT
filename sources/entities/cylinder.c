/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/05 11:24:00 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cylinder	*cylinder_new(char **tokens)
{
	char		**c;
	char		**n;
	char		**cl;
	t_cylinder	*cy;

	cy = nc_calloc(1, sizeof(t_cylinder));
	if (!cy)
		return (NULL);
	c = nc_split(tokens[1], ',');
	n = nc_split(tokens[2], ',');
	cl = nc_split(tokens[5], ',');
	*cy = (t_cylinder)
	{
		.radius = nc_atof(tokens[3]) / 2,
		.height = nc_atof(tokens[4]),
		.center = vec3_new(nc_atof(c[X]), nc_atof(c[Y]), nc_atof(c[Z])),
		.normal = vec3_new(nc_atof(n[X]), nc_atof(n[Y]), nc_atof(n[Z])),
		.color = color_new(nc_atof(cl[R]), nc_atof(cl[G]), nc_atof(cl[B])),
	};
	nc_matrix_delete(c, &free);
	nc_matrix_delete(n, &free);
	nc_matrix_delete(cl, &free);
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
	printf("  Center: (%.2f, %.2f, %.2f)\n", \
		c->center.x, c->center.y, c->center.z);
	printf("  Normal: (%.2f, %.2f, %.2f)\n", \
		c->normal.x, c->normal.y, c->normal.z);
	printf("  Radius: %.2f\n", c->radius);
	printf("  Height: %.2f\n", c->height);
	printf("  Color: (%d, %d, %d)\n", c->color.r, c->color.g, c->color.b);
}
