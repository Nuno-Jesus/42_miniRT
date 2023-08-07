/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:38:21 by maricard          #+#    #+#             */
/*   Updated: 2023/08/07 16:02:23 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	sphere_normal(t_inter *inter, *ray)
{
	t_vec3	point;
	t_vec3	normal;
	
	point = vec3_add(ray->origin, vec3_scale(ray->direction, inter->t));
	normal = vec3_sub(point, ray->origin);
	inter->normal = normal;
}

void	plane_normal(t_inter *inter, t_plane *pl, t_ray *ray)
{
	pl->normal = inter->normal;
}

//void	cylinder_normal(t_inter *inter, t_cylinder *cy, *ray)
//{
//	t_vec3	point;
//	t_vec3	normal;
	
//	point = vec3_add(ray->origin, vec3_scale(ray->direction, inter->data->t));
//	normal = vec3_sub(point, ray->origin);
//	inter->data->normal = normal;
//}

void	normal(t_inter *inter, t_ray *ray)
{
	if (inter->shape->type == PLANE)
		plane_normal(inter, ray);
	else if (inter->shape->type == SPHERE)
		sphere_normal(inter, inter->shape->data.sp, ray);
	//else if (inter->shape->type == CYLINDER)
	//	cylinder_normal(inter, inter->shape->data, ray);
}