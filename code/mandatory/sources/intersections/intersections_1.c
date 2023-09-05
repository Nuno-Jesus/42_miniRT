/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:53:41 by crypto            #+#    #+#             */
/*   Updated: 2023/08/14 16:56:39 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	intersects(t_shape *shape, t_ray *ray, t_hit *inter)
{
	if (shape->type == SPHERE)
		return (sphere_intersect(&shape->data.sp, ray, inter));
	else if (shape->type == PLANE)
		return (plane_intersect(&shape->data.pl, ray, inter));
	else if (shape->type == CYLINDER)
		return (cylinder_intersect(&shape->data.cy, ray, inter));
	return (false);
}

bool	plane_intersect(t_plane *pl, t_ray *ray, t_hit *inter)
{
	t_vec3		co;
	t_equation	equation;

	if (vec3_dot(ray->direction, pl->normal) != 0.0)
	{
		co = vec3_sub(ray->origin, pl->center);
		equation.a = 0;
		equation.b = vec3_dot(ray->direction, pl->normal);
		equation.c = vec3_dot(co, pl->normal);
		solve(&equation);
		if (equation.t1 > EPSILON)
		{
			inter->t = equation.t1;
			inter->color = pl->color;
			return (true);
		}
	}
	return (false);
}

bool	sphere_intersect(t_sphere *sp, t_ray *ray, t_hit *inter)
{
	t_vec3		co;
	t_equation	equation;

	equation.t1 = -1.0f;
	co = vec3_sub(ray->origin, sp->center);
	equation.a = vec3_dot(ray->direction, ray->direction);
	equation.b = 2.0f * vec3_dot(co, ray->direction);
	equation.c = vec3_dot(co, co) - pow(sp->radius, 2);
	if (solve(&equation) > 0 && \
		(equation.t1 > EPSILON || equation.t2 > EPSILON))
	{
		if (equation.t1 > EPSILON)
			inter->t = equation.t1;
		else
			inter->t = equation.t2;
		inter->color = sp->color;
		return (true);
	}
	return (false);
}
