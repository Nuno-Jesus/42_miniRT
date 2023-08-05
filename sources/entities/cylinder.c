/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/05 16:46:59 by ncarvalh         ###   ########.fr       */
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
	t_vec3	co;
	t_equation	equation;
	// t_vec3	cap;
	
	// cap = vec3_sub(cy->center, vec3_scale(cy->normal, cy->height / 2.0));
	co = vec3_sub(ray->origin, cy->center);
	equation.a = vec3_dot(ray->direction, ray->direction) - pow(vec3_dot(ray->direction, cy->normal), 2);
	equation.b = 2 * (vec3_dot(ray->direction, co) - vec3_dot(ray->direction, cy->normal) * vec3_dot(co, cy->normal));
	equation.c = vec3_dot(co, co) - pow(vec3_dot(co, cy->normal), 2) - pow(cy->radius, 2);
	// printf("a = %f\n", a);
	// printf("b = %f\n", b);
	// printf("c = %f\n", c);

	//Print the result of the determinant
	// printf("Determinant = %f\n", determinant(a, b, c));
	if (quadformula(&equation) == 0)
		return (false);
	double m1;
	double m2;

	m1 = vec3_dot(ray->direction, cy->normal) * equation.t1 + vec3_dot(co, cy->normal);
	m2 = vec3_dot(ray->direction, cy->normal) * equation.t2 + vec3_dot(co, cy->normal);
	// t_vec3 inter, inter2;

	// inter = vec3_add(ray->origin, vec3_scale(ray->direction, roots[0]));
	// inter2 = vec3_add(ray->origin, vec3_scale(ray->direction, roots[1]));
	if (m1 >= -cy->height / 2 && m1 <= cy->height / 2)
	{
		// printf("========= ============\n");
		// printf("x1 = %3.f m1 = %3.f inter 1:", roots[0], m1);
		// vec3_print(inter);
		return (true);
	}
	if (m2 >= -cy->height / 2 && m2 <= cy->height / 2)
	{
		// printf("========= ============\n");
		// printf("x2 = %3.f m2 = %3.f inter 2:", roots[1], m2);
		// vec3_print(inter2);
		return (true);
	}
	return (false);
}

