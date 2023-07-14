/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/14 17:36:30 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cylinder	cylinder_new(char **tokens)
{
	char		**c;
	char		**n;
	char		**cl;
	t_cylinder	cy;

	c = nc_split(tokens[1], ',');
	n = nc_split(tokens[2], ',');
	cl = nc_split(tokens[5], ',');
	cy = (t_cylinder)
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

bool	cylinder_intersect(t_cylinder *cy, t_ray *ray)
{
	float	a;
	float 	b;
	float 	c;
	float	roots[2];
	t_vec3	co;
	
	co = vec3_sub(ray->origin, cy->center);
	a = vec3_dot(ray->direction, ray->direction) - pow(vec3_dot(ray->direction, cy->normal), 2);
	b = 2 * (vec3_dot(ray->direction, co) - vec3_dot(ray->direction, cy->normal) * vec3_dot(co, cy->normal));
	c = vec3_dot(co, co) - pow(vec3_dot(co, cy->normal), 2) - pow(cy->radius, 2);
	// printf("a = %f\n", a);
	// printf("b = %f\n", b);
	// printf("c = %f\n", c);

	//Print the result of the determinant
	// printf("Determinant = %f\n", determinant(a, b, c));
	if (quadformula(a, b, c, roots) == 0)
		return (false);
	if (roots[0] < 0 || roots[0] > cy->height)
		return (false);
	return (true);
}

