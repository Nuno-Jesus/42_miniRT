/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/08 20:08:18 by maricard         ###   ########.fr       */
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

double	cap_intersection(t_cylinder *cy, t_ray *ray, t_vec3 cap)
{
	t_vec3	co;
	t_vec3	vec;
	double 	numerator;
	double 	denominator;
	double 	t;

	t = -1;
	vec = vec3_sub(cy->normal, cap);
	if (vec3_dot(ray->direction, vec) != 0.0)
	{
		co = vec3_sub(ray->origin, cap);
		numerator = vec3_dot(co, vec3_add(cy->normal, vec3_new(EPSILON, EPSILON, EPSILON)));
		denominator = vec3_dot(ray->direction, vec3_add(cy->normal, vec3_new(EPSILON, EPSILON, EPSILON)));
		t = -(numerator / denominator);
		return (t);
	}
	return (t);
}

bool	check_walls(t_cylinder *cy, t_ray *ray, double t1, double t2)
{
	t_vec3	vec1;
	t_vec3	vec2;
	t_vec3	co1;
	t_vec3	co2;
	double 	d1;

	vec1 = ray_at(ray, t1);
	vec2 = ray_at(ray, t2);
	co1 = vec3_sub(ray->origin, cy->cap1);
	co2 = vec3_sub(ray->origin, cy->cap2);
	
}

double	check_points(t_cylinder *cy, t_ray *ray, t_equation *equation)
{
	double t;
	double t1;
	double t2;
	double t3;
	double t4;

	t1 = equation->t1;
	t2 = equation->t2;
	t3 = cap_intersection(cy, ray, cy->cap1);
	t4 = cap_intersection(cy, ray, cy->cap2);
	if (check_walls(cy, ray, t1, t2))
		return (t1);
}

bool	cylinder_intersect(t_cylinder *cy, t_ray *ray, t_inter *inter)
{
	t_vec3		co;
	t_equation	equation;
	double t;

	(void)inter;
	co = vec3_sub(ray->origin, cy->cap1);
	equation.a = vec3_dot(ray->direction, ray->direction) - pow(vec3_dot(ray->direction, cy->normal), 2);
	equation.b = 2 * (vec3_dot(ray->direction, co) - (vec3_dot(ray->direction, cy->normal) * vec3_dot(co, cy->normal)));
	equation.c = vec3_dot(co, co) - pow(vec3_dot(co, cy->normal), 2) - pow(cy->radius, 2);
	if (quadformula(&equation) <= 0)
		return (false);
	t = check_points(cy, ray, &equation);
	if (t)
	{
		inter->t = equation.t1;
		inter->color = cy->color;
		return (true);
	}
	return (false);
}





//bool	cylinder_intersect(t_cylinder *cy, t_ray *ray, t_inter *inter)
//{
//	(void) inter;
//	t_vec3		co;
//	t_equation	equation;
//	double m1;

//	co = vec3_sub(ray->origin, cy->cap1);
//	equation.a = vec3_dot(ray->direction, ray->direction) - pow(vec3_dot(ray->direction, cy->normal), 2);
//	equation.b = 2 * (vec3_dot(ray->direction, co) - vec3_dot(ray->direction, cy->normal) * vec3_dot(co, cy->normal));
//	equation.c = vec3_dot(co, co) - pow(vec3_dot(co, cy->normal), 2) - pow(cy->radius, 2);
//	if (quadformula(&equation) <= 0)
//		return (false);
//	m1 = vec3_dot(ray->direction, cy->normal) * equation.t1 + vec3_dot(co, cy->normal);
//	if (m1 >= EPSILON && m1 <= cy->height)
//	{
//		inter->t = equation.t1;
//		inter->color = cy->color;	
//		return (true);
//	}
//	return (false);
//}
