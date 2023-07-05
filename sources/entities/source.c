/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:25:05 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/05 11:29:06 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_lightsource	*source_new(char **c, char *brightness, char **cl)
{
	t_lightsource	*lightsource;

	lightsource = nc_calloc(1, sizeof(t_lightsource));
	if (!lightsource)
		return (NULL);
	*lightsource = (t_lightsource)
	{
		.origin = vec3_new(nc_atof(c[X]), nc_atof(c[Y]), nc_atof(c[Z])), 
		.brightness = nc_atof(brightness),
		.color = color_new(nc_atof(cl[R]), nc_atof(cl[G]), nc_atof(cl[B])), 
	};
	return (lightsource);
}

t_lightsource	*source_copy(t_lightsource *lightsource)
{
	t_lightsource	*copy;

	copy = nc_calloc(1, sizeof(t_lightsource));
	if (!copy)
		return (NULL);
	*copy = *lightsource;
	return (copy);
}

void	source_print(t_lightsource *l)
{
	printf("Lightsource:\n");
	printf("  Point: (%.2f, %.2f, %.2f)\n", \
		l->origin.x, l->origin.y, l->origin.z);
	printf("  Ratio: %.2f\n", l->brightness);
	printf("  Color: (%d, %d, %d)\n", l->color.r, l->color.g, l->color.b);
}
