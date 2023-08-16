/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:03:15 by maricard          #+#    #+#             */
/*   Updated: 2023/08/15 16:11:24 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	torus_intersect(t_cylinder *to, t_ray *ray, t_hit *inter)
{
	t_vec3		co;
	t_equation	equation;

	equation.t1 = -1.0f;
	co = vec3_sub(ray->origin, to->center);
	equation.a = vec3_dot(ray->direction, ray->direction);
	equation.b = 2.0f * vec3_dot(co, ray->direction);
	equation.c = vec3_dot(co, co) - pow(to->radius, 2);
	if (solve(&equation) > 0 && \
		(equation.t1 > EPSILON || equation.t2 > EPSILON))
	{
		if (equation.t1 > EPSILON)
			inter->t = equation.t1;
		else
			inter->t = equation.t2;
		inter->color = to->color;
		return (true);
	}
	return (false);
}
