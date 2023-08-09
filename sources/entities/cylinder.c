/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 17:52:28 by maricard         ###   ########.fr       */
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
		.normal = vec3_normalize(vec3_new(nc_atof(n[X]), nc_atof(n[Y]), nc_atof(n[Z]))),
		.color = color_new(nc_atof(cl[R]), nc_atof(cl[G]), nc_atof(cl[B])),
	};
	cy.cap1 = vec3_add(cy.center, vec3_scale(cy.normal, -cy.height / 2.0));
	cy.cap2 = vec3_add(cy.center, vec3_scale(cy.normal, cy.height / 2.0));
	nc_matrix_delete(c, &free);
	nc_matrix_delete(n, &free);
	nc_matrix_delete(cl, &free);
	return (cy);
}

bool	check_caps(t_cylinder *cy, t_vec3 cap, t_inter *inter, double t)
{
	double	len;
	t_vec3	point;

	point = ray_at(&inter->ray, t);
	len = vec3_module(vec3_sub(point, cap));
	len += EPSILON;
	if (len <= cy->radius && t < inter->t)
	{
		inter->a = cap;
		inter->t = t;
		return (true);
	}
	else 
		return (false);
}

bool	check_walls(t_cylinder *cy, t_inter *inter, double t)
{
	t_vec3	point;
	t_vec3	co;
	t_vec3	a;
	double 	m;
	double 	len;

	point = ray_at(&inter->ray, t);
	co = vec3_sub(inter->ray.origin, cy->cap1);
	m = vec3_dot(inter->ray.direction, cy->normal) * t + vec3_dot(co, cy->normal);
	a = vec3_add(cy->cap1, vec3_scale(cy->normal, m));
	len = vec3_module(vec3_sub(point, a));
	m -= EPSILON;
	len -= EPSILON;
	if (m >= 0 && m <= cy->height && len <= cy->radius && t < inter->t)
	{
		inter->a = a;
		inter->t = t;
		return (true);		
	}
	else
		return (false);
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
		numerator = vec3_dot(co, vec3_add(cy->normal, \
						vec3_new(EPSILON, EPSILON, EPSILON)));
		denominator = vec3_dot(ray->direction, vec3_add(cy->normal, \
						vec3_new(EPSILON, EPSILON, EPSILON)));
		t = -(numerator / denominator);
		return (t);
	}
	return (t);
}

double	verify_intersections(t_cylinder *cy, t_ray *ray, t_equation *equation, t_inter *inter)
{
	double t1;
	double t2;
	double t3;
	double t4;

	t1 = equation->t1;
	t2 = equation->t2;
	t3 = cap_intersection(cy, ray, cy->cap1);
	t4 = cap_intersection(cy, ray, cy->cap2);
	inter->t = INFINITY;
	inter->ray = *ray;
	check_walls(cy, inter, t1);
	check_walls(cy, inter, t2);
	check_caps(cy, cy->cap1, inter, t3);
	check_caps(cy, cy->cap2, inter, t4);
	if (inter->t == INFINITY)
		return (0);
	return (inter->t);
}

bool	cylinder_intersect(t_cylinder *cy, t_ray *ray, t_inter *inter)
{
	t_vec3		co;
	t_equation	equation;
	double 		t;

	co = vec3_sub(ray->origin, cy->cap1);
	equation.a = vec3_dot(ray->direction, ray->direction) - \
					pow(vec3_dot(ray->direction, cy->normal), 2);
	equation.b = 2 * (vec3_dot(ray->direction, co) - \
		(vec3_dot(ray->direction, cy->normal) * vec3_dot(co, cy->normal)));
	equation.c = vec3_dot(co, co) - pow(vec3_dot(co, cy->normal), 2) - \
					pow(cy->radius, 2);
	quadformula(&equation);
	if (equation.t1 <= 0 && equation.t2 <= 0)
		return (false);
	t = verify_intersections(cy, ray, &equation, inter);
	if (t > 0.0f)
	{
		inter->t = t;
		inter->color = cy->color;
		return (true);
	}
	return (false);
}
