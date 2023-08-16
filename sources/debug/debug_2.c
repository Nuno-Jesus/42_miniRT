/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:34:42 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/15 15:50:18 by maricard         ###   ########.fr       */
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
	else if (shape->type == TORUS)
		torus_print(&shape->data.to);
	printf("  ID: %d\n", shape->id);
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

void	torus_print(t_torus *to)
{
	printf("Torus:\n");
	printf("  Center: (%.4lf, %.4lf, %.4lf)\n", \
		to->center.x, to->center.y, to->center.z);
	printf("  Normal: (%.4lf, %.4lf, %.4lf)\n", \
		to->normal.x, to->normal.y, to->normal.z);
	printf("  R1: %.4lf\n", to->r1);
	printf("  R2: %.4lf\n", to->r2);
	printf("  Color: (%d, %d, %d)\n", to->color.r, to->color.g, to->color.b);
}

void	world_print(t_world *world)
{
	printf("\n\t================ DEBUG ================\n\n");
	ambient_print(&world->ambient);
	camera_print(&world->camera);
	nc_vector_print(world->lights);
	nc_vector_print(world->shapes);
	printf("Right Vector:\n  ");
	vec3_print(world->right);
	printf("Up Vector:\n  ");
	vec3_print(world->up);
	printf("Viewport:\n");
	printf("  Height: %lf\n", world->hview);
	printf("  Width: %lf\n", world->wview);
	printf("\n\t=======================================\n\n");
}
