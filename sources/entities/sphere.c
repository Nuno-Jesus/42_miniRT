/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/13 15:42:36 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_sphere	sphere_new(char **c, char *radius, char **cl)
{
	t_sphere	sp;

	sp = (t_sphere)
	{
		.origin = vec3_new(nc_atof(c[X]), nc_atof(c[Y]), nc_atof(c[Z])), 
		.radius = nc_atof(radius) / 2,
		.color = color_new(nc_atof(cl[R]), nc_atof(cl[G]), nc_atof(cl[B])), 
	};
	return (sp);
}
