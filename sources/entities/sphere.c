/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:09:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/03 13:06:29 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_sphere	sphere_new(char **c, char *radius, char **cl)
{
	t_sphere	sp;

	sp = (t_sphere)
	{
		.origin = vec3_new(nc_atof(c[X]), nc_atof(c[Y]), nc_atof(c[Z])), 
		.radius = nc_atof(radius) / 2,
		.color = color_new(nc_atof(cl[R]), nc_atof(cl[G]), nc_atof(cl[B])), 
	};
	return (sp);
}

//! C = center of the sphere
//! O = origin of the ray
//! D = direction of the ray
//! a = D . D
//! b = 2 * (CO . D)
//! C = CO. CO - r^2

bool	sphere_intersect(t_sphere *sp, t_ray *ray)
{
	double	a;
	double 	b;
	double 	c;
	double 	t;
	t_vec3	co;
	
	t = -1.0f;
	co = vec3_sub(ray->origin, sp->origin);
	a = vec3_dot(ray->direction, ray->direction);
	b = 2.0f * vec3_dot(co, ray->direction);
	c = vec3_dot(co, co) - pow(sp->radius, 2);
	if (formula(a, b, c, &t) > 0 && t > EPSILON)
		closest_point(t, ray, &sp->color);
	// printf("a = %f\n", a);
	// printf("b = %f\n", b);
	// printf("c = %f\n", c);

	//Print the result of the determinant
	// printf("Determinant = %f\n", determinant(a, b, c));
	return (determinant(a, b, c) > 0);
}
