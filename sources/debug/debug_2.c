/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:34:42 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 19:17:36 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	sphere_print(t_sphere *s)
{
	printf("Sphere:\n");
	printf("  Center: (%.2f, %.2f, %.2f)\n", \
		s->center.x, s->center.y, s->center.z);
	printf("  Radius: %.2f\n", s->radius);
	printf("  Color: (%d, %d, %d)\n", s->color.r, s->color.g, s->color.b);
}
