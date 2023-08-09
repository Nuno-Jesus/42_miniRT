/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:34:42 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 21:20:47 by crypto           ###   ########.fr       */
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
}

void	sphere_print(t_sphere *s)
{
	printf("Sphere:\n");
	printf("  Center: (%.2f, %.2f, %.2f)\n", \
		s->center.x, s->center.y, s->center.z);
	printf("  Radius: %.2f\n", s->radius);
	printf("  Color: (%d, %d, %d)\n", s->color.r, s->color.g, s->color.b);
}

void	cylinder_print(t_cylinder *c)
{
	printf("Cylinder:\n");
	printf("  Center: (%.2f, %.2f, %.2f)\n", \
		c->center.x, c->center.y, c->center.z);
	printf("  Normal: (%.2f, %.2f, %.2f)\n", \
		c->normal.x, c->normal.y, c->normal.z);
	printf("  Radius: %.2f\n", c->radius);
	printf("  Height: %.2f\n", c->height);
	printf("  Color: (%d, %d, %d)\n", c->color.r, c->color.g, c->color.b);
}

void	plane_print(t_plane *p)
{
	printf("Plane:\n");
	printf("  Point: %.2f, %.2f, %.2f\n", \
		p->center.x, p->center.y, p->center.z);
	printf("  Normal: %.2f, %.2f, %.2f\n", \
		p->normal.x, p->normal.y, p->normal.z);
	printf("  Color: (%d, %d, %d)\n", p->color.r, p->color.g, p->color.b);
}
