/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:53:41 by crypto            #+#    #+#             */
/*   Updated: 2023/08/15 16:05:24 by maricard         ###   ########.fr       */
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
	else if (shape->type == TORUS)
		return (torus_intersect(&shape->data.cy, ray, inter));
	return (false);
}
