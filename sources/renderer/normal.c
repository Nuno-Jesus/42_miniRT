/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:38:21 by maricard          #+#    #+#             */
/*   Updated: 2023/08/22 12:13:42 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	sphere_normal(t_hit *inter, t_ray *ray)
{
	t_vec3	point;
	t_vec3	normal;

	point = ray_at(ray, inter->t);
	normal = vec3_sub(point, inter->shape->data.sp.center);
	return (normal);
}

t_vec3	cylinder_normal(t_hit *inter, t_ray *ray)
{
	t_vec3	point;
	t_vec3	normal;

	point = ray_at(ray, inter->t);
	normal = vec3_sub(point, inter->a);
	if (vec3_compare(inter->a, inter->shape->data.cy.cap1))
		normal = vec3_scale(inter->shape->data.cy.normal, -1);
	else if (vec3_compare(inter->a, inter->shape->data.cy.cap2))
		normal = inter->shape->data.cy.normal;
	return (normal);
}

t_vec3	cone_normal(t_hit *inter, t_ray *ray)
{
	t_vec3	point;
	t_vec3	normal;
	t_vec3	tmp;
	double 	adj;
	double 	hip;

	point = ray_at(ray, inter->t);
	adj = vec3_length(vec3_sub(point, inter->shape->data.co.tip));
	hip = adj / cos(inter->shape->data.co.angle);
	tmp = vec3_add(inter->shape->data.co.tip, \
				vec3_scale(inter->shape->data.co.normal, hip));
	normal = vec3_sub(point, tmp);
	//printf("adj: %f\n", adj);
	//printf("hip: %f\n", hip);
	//printf("tmp: %f %f %f\n", tmp.x, tmp.y, tmp.z);
	//printf("point: %f %f %f\n", point.x, point.y, point.z);
	//printf("normal: %f %f %f\n", normal.x, normal.y, normal.z);
	//printf("t: %f\n", inter->t);
	//printf("-------------------\n");
	if (vec3_compare(inter->a, inter->shape->data.co.normal))
		normal = inter->shape->data.co.normal;
	else if (vec3_compare(point, inter->shape->data.co.tip))
		normal = vec3_scale(inter->shape->data.co.normal, -1);
	return (normal);
}

//t_vec3	cone_normal(t_hit *inter, t_ray *ray)
//{
//	t_vec3	point;
//	t_vec3	normal;
//	t_vec3	tmp;
//	t_vec3	tp;
	
//	point = ray_at(ray, inter->t);
//	tp = vec3_sub(point, inter->shape->data.co.tip);
//	tmp = vec3_scale(inter->shape->data.co.normal, vec3_dot(tp, inter->shape->data.co.normal));
//	normal = vec3_sub(tp, tmp);
//	if (vec3_compare(inter->a, vec3_scale(inter->shape->data.co.tip, \
//				inter->shape->data.co.height)))
//		normal = inter->shape->data.co.normal;
//	return (normal);
//}

t_vec3	shape_normal(t_hit *inter, t_ray *ray)
{
	if (inter->shape->type == PLANE)
		return (inter->shape->data.pl.normal);
	else if (inter->shape->type == SPHERE)
		return (sphere_normal(inter, ray));
	else if (inter->shape->type == CYLINDER)
		return (cylinder_normal(inter, ray));
	else
		return (cone_normal(inter, ray));
}
