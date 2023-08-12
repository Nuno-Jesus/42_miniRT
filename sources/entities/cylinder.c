/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:29 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/12 16:19:13 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cylinder	cylinder_from_strings(char **tokens)
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
		.radius = nc_atod(tokens[3]) / 2.0,
		.height = nc_atod(tokens[4]),
		.center = vec3_new(nc_atod(c[X]), nc_atod(c[Y]), nc_atod(c[Z])),
		.normal = vec3_normalize(\
			vec3_new(nc_atod(n[X]), nc_atod(n[Y]), nc_atod(n[Z]))),
		.color = color_new(nc_atod(cl[R]), nc_atod(cl[G]), nc_atod(cl[B])),
	};
	cy.cap1 = vec3_add(cy.center, vec3_scale(cy.normal, -cy.height / 2.0));
	cy.cap2 = vec3_add(cy.center, vec3_scale(cy.normal, cy.height / 2.0));
	nc_matrix_delete(c, &free);
	nc_matrix_delete(n, &free);
	nc_matrix_delete(cl, &free);
	return (cy);
}

bool	check_caps(t_cylinder *cy, t_vec3 cap, t_hit *inter, double t)
{
	double	len;
	t_vec3	point;

	point = ray_at(&inter->ray, t);
	len = vec3_length(vec3_sub(point, cap));
	len += EPSILON;
	if (len <= cy->radius && t < inter->t)
	{
		inter->a = cap;
		inter->t = t;
		return (true);
	}
	return (false);
}

bool	check_walls(t_cylinder *cy, t_hit *inter, double t)
{
	t_vec3	point;
	t_vec3	co;
	t_vec3	a;
	double	m;
	double	len;

	point = ray_at(&inter->ray, t);
	co = vec3_sub(inter->ray.origin, cy->cap1);
	m = vec3_dot(inter->ray.direction, cy->normal) * t + \
		vec3_dot(co, cy->normal);
	a = vec3_add(cy->cap1, vec3_scale(cy->normal, m));
	len = vec3_length(vec3_sub(point, a));
	m -= EPSILON;
	len -= EPSILON;
	if (m >= 0 && m <= cy->height && len <= cy->radius && t < inter->t)
	{
		inter->a = a;
		inter->t = t;
		return (true);
	}
	return (false);
}
// t_vec3	co;
	// t_vec3	vec;
	// double 	numerator;
	// double 	denominator;
	// double 	t;

	// vec = vec3_sub(cy->normal, cap);
	// if (vec3_dot(ray->direction, vec) != 0.0)
	// {
	// 	co = vec3_sub(ray->origin, cap);
	// 	numerator = vec3_dot(co, cy->normal);
	// 	denominator = vec3_dot(ray->direction, cy->normal);
	// 	t = -(numerator / denominator);
	// 	return (t);
	// }
	// return (t);
double	cap_intersection(t_cylinder *cy, t_ray *ray, t_vec3 cap)
{
	t_plane	plane;
	t_hit	inter;

	plane = plane_from_numbers(cap, cy->normal, BLACK);
	if (plane_intersect(&plane, ray, &inter))
		return (inter.t);
	return (-1);
}

double	verify_intersections(t_cylinder *cy, t_ray *ray, \
	t_equation *equation, t_hit *inter)
{
	double	t1;
	double	t2;
	double	t3;
	double	t4;

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

bool	cylinder_intersect(t_cylinder *cy, t_ray *ray, t_hit *inter)
{
	double		t;
	t_vec3		co;
	t_equation	equation;

	co = vec3_sub(ray->origin, cy->cap1);
	equation.a = vec3_dot(ray->direction, ray->direction) - \
		pow(vec3_dot(ray->direction, cy->normal), 2);
	equation.b = 2 * (vec3_dot(ray->direction, co) - \
		(vec3_dot(ray->direction, cy->normal) * vec3_dot(co, cy->normal)));
	equation.c = vec3_dot(co, co) - pow(vec3_dot(co, cy->normal), 2) - \
		pow(cy->radius, 2);
	solve(&equation);
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
