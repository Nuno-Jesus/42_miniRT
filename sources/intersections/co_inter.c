/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:03:15 by maricard          #+#    #+#             */
/*   Updated: 2023/08/22 12:34:53 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_base(t_cone *co, t_vec3 cap, t_hit *inter, double t)
{
	double	len;
	t_vec3	point;

	point = ray_at(&inter->ray, t);
	len = vec3_length(vec3_sub(point, cap));
	len += EPSILON;
	if (len <= co->radius && t > EPSILON && t < inter->t)
	{
		inter->a = co->normal;
		inter->t = t;
		return (true);
	}
	return (false);
}

bool	check_sides(t_cone *co, t_hit *inter, double t)
{
	t_vec3	oc;
	t_vec3	tmp;
	t_vec3	point;
	double 	angle;
	double	m;

	point = ray_at(&inter->ray, t);
	oc = vec3_sub(inter->ray.origin, co->tip);
	m = vec3_dot(inter->ray.direction, co->normal) * t + \
			vec3_dot(oc, co->normal);
	tmp = vec3_sub(point, vec3_sub(co->tip, vec3_scale(co->normal, m)));
	angle = acos(vec3_dot(tmp, co->normal) / (vec3_length(tmp) * \
				vec3_length(co->normal)));
	if (m >= 0 && m <= co->height && angle <= co->angle && t > EPSILON \
			&& t < inter->t)
	{
		inter->a = vec3_add(co->tip, vec3_scale(co->normal, m));
		inter->t = t;
		return (true);
	}
	return (false);
}

double	cap_intersect(t_cone *co, t_ray *ray, t_vec3 cap)
{
	t_plane	plane;
	t_hit	inter;

	plane = plane_from_numbers(cap, co->normal, BLACK);
	if (plane_intersect(&plane, ray, &inter))
		return (inter.t);
	return (-1);
}

double	verify_intersects(t_cone *co, t_equation *equation, t_hit *inter)
{
	double	t1;
	double	t2;
	t_vec3 	base;

	if (!solve(equation))
		return (0);
	inter->t = INFINITY;
	base = vec3_add(co->tip, vec3_scale(co->normal, co->height));
	t1 = closest_value(equation->t1, equation->t2);
	t2 = cap_intersect(co, &inter->ray, base);
	//printf("t1: %f\n", equation->t1);
	//printf("t2: %f\n", equation->t2);
	//printf("t: %f\n", t1);
	//printf("-----------------\n");
	check_sides(co, inter, t1);
	check_base(co, base, inter, t2);
	if (inter->t == INFINITY || inter->t < 0)
		return (0);
	return (inter->t);
}

bool	cone_intersect(t_cone *co, t_ray *ray, t_hit *inter)
{
	t_vec3		oc;
	t_equation	equation;
	double 		t;
	
	inter->t = -1.0f;
	oc = vec3_sub(ray->origin, co->tip);
	equation.a = pow(vec3_dot(ray->direction, co->normal), 2) - \
					pow(cos(co->angle), 2);
	equation.b = 2.0f * (vec3_dot(ray->direction, co->normal) * \
					vec3_dot(oc, co->normal) - vec3_dot(ray->direction, oc) \
						* pow(cos(co->angle), 2));
	equation.c = pow(vec3_dot(oc, co->normal), 2) - vec3_dot(oc, oc) * \
					pow(cos(co->angle), 2);
	inter->ray = *ray;
	t = verify_intersects(co, &equation, inter);
	if (t > 0.0f)
	{
		inter->t = t;
		inter->color = co->color;
		return (true);
	}
	return (false);
}
