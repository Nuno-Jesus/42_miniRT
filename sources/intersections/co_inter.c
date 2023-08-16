/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:03:15 by maricard          #+#    #+#             */
/*   Updated: 2023/08/16 19:26:29 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double 	closest_value(double t1, double t2)
{
	if (t1 > EPSILON)
		return (t1);
	else if (t2 > EPSILON)
		return (t2);
	else
		return (-1.0f);
}

bool 	check_length(t_hit *inter, t_cone *co, double m)
{
	t_vec3	a;
	t_vec3	point;
	double 	h2;
	double	r2;
	double 	len;

	point = ray_at(&inter->ray, inter->t);
	a = vec3_add(co->tip, vec3_scale(co->normal, m));
	h2 = vec3_length(vec3_sub(a, co->tip));
	r2 = co->radius * h2 / co->height;
	len = vec3_length(vec3_sub(point, a));
	//printf("len = %f\n", len);
	////printf("r2 = %f\n", r2);
	if (len <= r2)
	{
		printf("entrei\n");
		return (true);
	}
	return (false);
}

bool	verify_intersection(t_equation eq, t_hit *inter, t_cone *co)
{
	double	m;
	bool	ok;

	if (!solve(&eq))
		return (false);
	inter->t = closest_value(eq.t1, eq.t2);
	inter->cp = vec3_add(inter->ray.origin, vec3_scale(inter->ray.direction, inter->t));
	inter->cp = vec3_sub(inter->cp, co->tip);
	inter->normal = co->normal;
	m = vec3_dot(inter->cp, co->normal);
	ok = check_length(inter, co, m);
	//printf("m = %f\n", m);
	if (m >= 0 && m <= co->height && ok && inter->t > 0)
	{
		//printf("t = %f\n", inter->t);
		//printf("point ");
		vec3_print(ray_at(&inter->ray, inter->t));
		return (true);
	}
	return (false);
}

bool	cone_intersect(t_cone *co, t_ray *ray, t_hit *inter)
{
	t_vec3		oc;
	t_equation	equation;
	
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
	if (verify_intersection(equation, inter, co) == true)
	{
		inter->color = co->color;
		return (true);
	}
	return (false);
}
