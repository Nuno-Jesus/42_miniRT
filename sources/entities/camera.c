/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:20:21 by maricard          #+#    #+#             */
/*   Updated: 2023/07/03 20:14:45 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	camera_print(t_camera *s)
{
	printf("Camera:\n");
	printf("  Center: (%.2f, %.2f, %.2f)\n", s->origin.x, s->origin.y, s->origin.z);
	printf("  Normal: %.2f, %.2f, %.2f\n", s->normal.x, s->normal.y, s->normal.z);
	printf("  Fov: %2.f\n", s->fov);
}