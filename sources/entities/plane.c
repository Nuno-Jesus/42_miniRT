/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/14 17:42:20 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_plane	plane_new(char **c, char **n, char **cl)
{
	t_plane	plane;

	plane = (t_plane)
	{
		.point = vec3_new(nc_atof(c[X]), nc_atof(c[Y]), nc_atof(c[Z])), 
		.normal = vec3_new(nc_atof(n[X]), nc_atof(n[Y]), nc_atof(n[Z])), 
		.color = color_new(nc_atof(cl[R]), nc_atof(cl[G]), nc_atof(cl[B])),
	};
	return (plane);
}

bool	plane_intersect(t_plane *pl, t_ray *ray)
{
	t_vec3	co;
	float 	numerator;
	float 	denominator;
	float 	result;

	if (vec3_dot(ray->direction, pl->normal) != 0)
	{
		co = vec3_sub(ray->origin, pl->point);
		numerator = vec3_dot(co, pl->normal);
		denominator = vec3_dot(ray->direction, pl->normal);
		result = numerator / denominator;
		closest_point(result, ray);
		return (true);
	}
	else
		return (false);
}
