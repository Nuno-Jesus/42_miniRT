/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:10:27 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/10 19:23:18 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//! C = center of the sphere
//! O = origin of the ray
//! D = direction of the ray
//! a = D . D
//! b = 2 * (CO . D)
//! C = CO. CO - r^2

bool	sphere_intersect(t_sphere *sp, t_ray *ray)
{
	float	a;
	float 	b;
	float 	c;
	t_vec3	co;

	co = vec3_sub(ray->origin, sp->origin);
	a = vec3_dot(ray->direction, ray->direction);
	b = 2.0f * vec3_dot(co, ray->direction);
	c = vec3_dot(co, co) - pow(sp->radius, 2);
	//Print the result of the determinant
	// printf("Determinant = %f\n", determinant(a, b, c));
	return (determinant(a, b, c) > 0);
}