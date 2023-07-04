/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:20:21 by maricard          #+#    #+#             */
/*   Updated: 2023/07/04 17:06:13 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	camera_print(t_camera *c)
{
	printf("Camera:\n");
	printf("  Center: (%.2f, %.2f, %.2f)\n", \
		c->origin.x, c->origin.y, c->origin.z);
	printf("  Normal: %.2f, %.2f, %.2f\n", \
		c->normal.x, c->normal.y, c->normal.z);
	printf("  Fov: %2.f\n", c->fov);
}
