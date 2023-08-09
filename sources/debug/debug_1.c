/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:34:30 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 21:21:23 by crypto           ###   ########.fr       */
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
		c->center.x, c->center.y, c->center.z);
	printf("  Normal: %.2f, %.2f, %.2f\n", \
		c->normal.x, c->normal.y, c->normal.z);
	printf("  Fov: %2.f\n", c->fov);
}

void	light_print(t_light *l)
{
	printf("Lightsource:\n");
	printf("  Point: (%.2f, %.2f, %.2f)\n", \
		l->center.x, l->center.y, l->center.z);
	printf("  Ratio: %.2f\n", l->ratio);
	printf("  Color: (%d, %d, %d)\n", l->color.r, l->color.g, l->color.b);
}

void	color_print(t_color *color)
{
	printf("#%02X%02X%02X\n", color->r, color->g, color->b);
}

void	vec3_print(t_vec3 vec)
{
	printf("Vec: (x, y, z) = (%.3f, %.3f, %.3f)\n", vec.x, vec.y, vec.z);
}
