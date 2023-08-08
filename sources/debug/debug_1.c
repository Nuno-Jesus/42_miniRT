/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:34:30 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/08 07:50:45 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ambient_print(t_light *s)
{
	printf("Ambient:\n");
	printf("  Ratio: (%.02f)\n", s->ratio);
	printf("  Color: (%d, %d, %d)\n", s->color.r, s->color.g, s->color.b);
}

void	camera_print(t_camera *c)
{
	printf("Camera:\n");
	printf("  Center: (%.2f, %.2f, %.2f)\n", \
		c->origin.x, c->origin.y, c->origin.z);
	printf("  Normal: %.2f, %.2f, %.2f\n", \
		c->normal.x, c->normal.y, c->normal.z);
	printf("  Fov: %2.f\n", c->fov);
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
		p->point.x, p->point.y, p->point.z);
	printf("  Normal: %.2f, %.2f, %.2f\n", \
		p->normal.x, p->normal.y, p->normal.z);
	printf("  Color: (%d, %d, %d)\n", p->color.r, p->color.g, p->color.b);
}

void	source_print(t_lightsource *l)
{
	printf("Lightsource:\n");
	printf("  Point: (%.2f, %.2f, %.2f)\n", \
		l->origin.x, l->origin.y, l->origin.z);
	printf("  Ratio: %.2f\n", l->brightness);
	printf("  Color: (%d, %d, %d)\n", l->color.r, l->color.g, l->color.b);
}
