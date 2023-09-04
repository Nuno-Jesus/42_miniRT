/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:34:42 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/04 13:31:30 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	shape_print(t_shape *shape)
{
	if (shape->type == PLANE)
		plane_print(&shape->data.pl);
	else if (shape->type == SPHERE)
		sphere_print(&shape->data.sp);
	else if (shape->type == CYLINDER)
		cylinder_print(&shape->data.cy);
	else if (shape->type == CONE)
		cone_print(&shape->data.co);
	printf("  ID: %d\n", shape->id);
	printf("  Textured? %d\n", shape->is_textured);
	printf("  Specular Coefficient (Ks): %lf\n", shape->ks);
	printf("  Shininess (n): %lf\n", shape->shininess);
}

void	sphere_print(t_sphere *s)
{
	printf("Sphere:\n");
	printf("  Center: (%.4lf, %.4lf, %.4lf)\n", \
		s->center.x, s->center.y, s->center.z);
	printf("  Radius: %.4lf\n", s->radius);
	printf("  Color: (%d, %d, %d)\n", s->color.r, s->color.g, s->color.b);
}

void	cylinder_print(t_cylinder *c)
{
	printf("Cylinder:\n");
	printf("  Center: (%.4lf, %.4lf, %.4lf)\n", \
		c->center.x, c->center.y, c->center.z);
	printf("  Normal: (%.4lf, %.4lf, %.4lf)\n", \
		c->normal.x, c->normal.y, c->normal.z);
	printf("  Radius: %.4lf\n", c->radius);
	printf("  Height: %.4lf\n", c->height);
	printf("  Color: (%d, %d, %d)\n", c->color.r, c->color.g, c->color.b);
}

void	plane_print(t_plane *p)
{
	printf("Plane:\n");
	printf("  Point: %.4lf, %.4lf, %.4lf\n", \
		p->center.x, p->center.y, p->center.z);
	printf("  Normal: %.4lf, %.4lf, %.4lf\n", \
		p->normal.x, p->normal.y, p->normal.z);
	printf("  Color: (%d, %d, %d)\n", p->color.r, p->color.g, p->color.b);
}

void	cone_print(t_cone *co)
{
	printf("Cone:\n");
	printf("  Center: (%.4lf, %.4lf, %.4lf)\n", \
		co->tip.x, co->tip.y, co->tip.z);
	printf("  Normal: (%.4lf, %.4lf, %.4lf)\n", \
		co->normal.x, co->normal.y, co->normal.z);
	printf("  Radius: %.4lf\n", co->radius);
	printf("  Height: %.4lf\n", co->height);
	printf("  Color: (%d, %d, %d)\n", co->color.r, co->color.g, co->color.b);
}
