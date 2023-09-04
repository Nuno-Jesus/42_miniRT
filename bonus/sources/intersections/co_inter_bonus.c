/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:03:15 by maricard          #+#    #+#             */
/*   Updated: 2023/09/04 13:44:35 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_base(t_cone *co, t_vec3 cap, t_hit *inter, double t)
{
	double	len;
	t_vec3	point;

	point = ray_at(&inter->ray, t);
	len = vec3_length(vec3_sub(point, cap));
	len -= EPSILON;
	if (len >= 0 && len <= co->radius && t > EPSILON && t < inter->t)
	{
		inter->a = co->normal;
		inter->t = t;
		inter->m = co->height;
		return (true);
	}
	return (false);
}

bool	check_sides(t_cone *co, t_hit *inter, double t)
{
	t_vec3	oc;
	t_vec3	tmp;
	t_vec3	point;
	double	angle;
	double	m;

	point = ray_at(&inter->ray, t);
	oc = vec3_sub(inter->ray.origin, co->tip);
	m = vec3_dot(inter->ray.direction, co->normal) * t + vec3_dot(oc,
			co->normal);
	tmp = vec3_sub(point, co->tip);
	angle = acos(vec3_cossine(co->normal, tmp)) - 0.001;
	if (m >= 0 && m <= co->height && angle - EPSILON <= co->angle && t > EPSILON
		&& t < inter->t)
	{
		inter->a = vec3_add(co->tip, vec3_scale(co->normal, m));
		inter->m = m;
		inter->t = t;
		return (true);
	}
	return (false);
}

double	cap_intersect(t_cone *co, t_ray *ray, t_vec3 cap)
{
	t_plane	plane;
	t_hit	inter;

	plane = plane_from_numbers(cap, co->normal, co->color);
	if (plane_intersect(&plane, ray, &inter))
		return (inter.t);
	return (-1);
}

double	verify_intersects(t_cone *co, t_equation *equation, t_hit *inter)
{
	double	t3;

	if (!solve(equation))
		return (0);
	inter->t = INFINITY;
	t3 = cap_intersect(co, &inter->ray, co->base);
	check_sides(co, inter, equation->t1);
	check_sides(co, inter, equation->t2);
	check_base(co, co->base, inter, t3);
	if (inter->t == INFINITY || inter->t < 0)
		return (0);
	return (inter->t);
}

bool	cone_intersect(t_cone *co, t_ray *ray, t_hit *inter)
{
	t_vec3		oc;
	t_equation	equation;
	double		t;

	inter->t = -1.0f;
	equation = (t_equation){0, 0, 0, 0, 0};
	oc = vec3_sub(ray->origin, co->tip);
	equation.a = pow(vec3_dot(ray->direction, co->normal), 2)
		- pow(cos(co->angle), 2);
	equation.b = 2.0f * (vec3_dot(ray->direction, co->normal) * vec3_dot(oc,
				co->normal) - vec3_dot(ray->direction, oc) * pow(cos(co->angle),
				2));
	equation.c = pow(vec3_dot(oc, co->normal), 2) - vec3_dot(oc, oc)
		* pow(cos(co->angle), 2);
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
