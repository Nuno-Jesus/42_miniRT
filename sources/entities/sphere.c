/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/04 17:08:47 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_sphere	*sphere_new(char **center, char *radius, char **color)
{
	t_sphere	*sp;

	sp = nc_calloc(1, sizeof(t_sphere));
	if (!sp)
		return (NULL);
	*sp = (t_sphere)
	{
		.origin.x = nc_atof(center[0]),
		.origin.y = nc_atof(center[1]),
		.origin.z = nc_atof(center[2]),
		.radius = nc_atof(radius),
		.color.r = nc_atoi(color[0]),
		.color.g = nc_atoi(color[1]),
		.color.b = nc_atoi(color[2])
	};
	return (sp);
}

t_sphere	*sphere_copy(t_sphere *sphere)
{
	t_sphere	*copy;

	copy = nc_calloc(1, sizeof(t_sphere));
	if (!copy)
		return (NULL);
	*copy = *sphere;
	return (copy);
}

void	sphere_print(t_sphere *s)
{
	printf("Sphere:\n");
	printf("  Center: (%.2f, %.2f, %.2f)\n", \
		s->origin.x, s->origin.y, s->origin.z);
	printf("  Radius: %.2f\n", s->radius);
	printf("  Color: (%d, %d, %d)\n", s->color.r, s->color.g, s->color.b);
}
