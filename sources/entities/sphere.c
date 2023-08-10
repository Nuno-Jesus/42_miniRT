/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/10 17:40:27 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_sphere	sphere_from_strings(char **tokens)
{
	char		**c;
	char		**cl;
	t_sphere	sp;

	c = nc_split(tokens[1], ',');
	cl = nc_split(tokens[3], ',');
	sp = (t_sphere)
	{
		.center = vec3_new(nc_atof(c[X]), nc_atof(c[Y]), nc_atof(c[Z])), 
		.radius = nc_atof(tokens[2]) / 2,
		.color = color_new(nc_atof(cl[R]), nc_atof(cl[G]), nc_atof(cl[B])), 
	};
	nc_matrix_delete(c, &free);
	nc_matrix_delete(cl, &free);
	return (sp);
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
	if (solve(&equation) > 0 && equation.t1 > EPSILON)
	{
		inter->t = equation.t1;
		inter->color = sp->color;
		return (true);
	}
	return (false);
}
