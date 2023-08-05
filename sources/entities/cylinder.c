/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/05 17:21:25 by ncarvalh         ###   ########.fr       */
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
	cy.cap1 = vec3_add(cy.center, vec3_scale(cy.normal, -cy.height / 2.0));
	cy.cap2 = vec3_add(cy.center, vec3_scale(cy.normal, cy.height / 2.0));
	nc_matrix_delete(c, &free);
	nc_matrix_delete(n, &free);
	nc_matrix_delete(cl, &free);
	return (cy);
}

bool	cylinder_intersect(t_cylinder *cy, t_ray *ray)
{
	t_vec3		co;
	t_equation	equation;
	double m1;
	double m2;

	co = vec3_sub(ray->origin, cy->cap1);
	equation.a = vec3_dot(ray->direction, ray->direction) - pow(vec3_dot(ray->direction, cy->normal), 2);
	equation.b = 2 * (vec3_dot(ray->direction, co) - vec3_dot(ray->direction, cy->normal) * vec3_dot(co, cy->normal));
	equation.c = vec3_dot(co, co) - pow(vec3_dot(co, cy->normal), 2) - pow(cy->radius, 2);
	if (quadformula(&equation) <= 0)
		return (false);
	m1 = vec3_dot(ray->direction, cy->normal) * equation.t1 + vec3_dot(co, cy->normal);
	m2 = vec3_dot(ray->direction, cy->normal) * equation.t2 + vec3_dot(co, cy->normal);
	if (m1 >= EPSILON && m1 <= cy->height)
	{
		closest_point(equation.t1, ray, &cy->color);
		return (true);
	}
	if (m2 >= EPSILON && m2 <= cy->height)
	{
		closest_point(equation.t2, ray, &cy->color);
		return (true);
	}
	return (false);
}

