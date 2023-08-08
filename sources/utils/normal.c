/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:38:21 by maricard          #+#    #+#             */
/*   Updated: 2023/08/08 15:32:34 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	sphere_normal(t_inter *inter, t_ray *ray)
{
	t_vec3	point;
	t_vec3	normal;
	
	point = ray_at(ray, inter->t);
	// printf("point: ");
	// vec3_print(point);
	normal = vec3_sub(point, inter->shape->data.sp.origin);
	return (normal);
}

//t_vec3	cylinder_normal(t_inter *inter, t_cylinder *cy, *ray)
//{
//	t_vec3	point;
//	t_vec3	normal;
	
//	point = vec3_add(ray->origin, vec3_scale(ray->direction, inter->data->t));
//	normal = vec3_sub(point, ray->origin);
// return (normal);
//}

t_vec3	normal(t_inter *inter, t_ray *ray)
{
	if (inter->shape->type == PLANE)
		return (inter->shape->data.pl.normal);
	else if (inter->shape->type == SPHERE)
		return (sphere_normal(inter, ray));
	else
		return (vec3_new(0, 1, 0));
	//else if (inter->shape->type == CYLINDER)
	//	cylinder_normal(inter, inter->shape->data, ray);
}