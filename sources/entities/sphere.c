/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/12 17:31:45 by ncarvalh         ###   ########.fr       */
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
		.center = vec3_new(nc_atod(c[X]), nc_atod(c[Y]), nc_atod(c[Z])), 
		.radius = nc_atod(tokens[2]) / 2.0,
		.color = color_new(nc_atod(cl[R]), nc_atod(cl[G]), nc_atod(cl[B])), 
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
