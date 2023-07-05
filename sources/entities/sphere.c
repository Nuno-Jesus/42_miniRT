/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/05 11:29:00 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_sphere	*sphere_new(char **c, char *radius, char **cl)
{
	t_sphere	*sp;

	sp = nc_calloc(1, sizeof(t_sphere));
	if (!sp)
		return (NULL);
	*sp = (t_sphere)
	{
		.origin = vec3_new(nc_atof(c[X]), nc_atof(c[Y]), nc_atof(c[Z])), 
		.radius = nc_atof(radius) / 2,
		.color = color_new(nc_atof(cl[R]), nc_atof(cl[G]), nc_atof(cl[B])), 
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
