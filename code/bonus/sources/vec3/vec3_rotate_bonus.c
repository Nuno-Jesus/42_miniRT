/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:00:43 by crypto            #+#    #+#             */
/*   Updated: 2023/09/04 10:27:13 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_rotate(t_vec3 vec, int axis, double angle)
{
	t_vec3	rotated;

	rotated = vec;
	if (axis == X)
	{
		rotated.y = vec.y * cos(angle) - vec.z * sin(angle);
		rotated.z = vec.y * sin(angle) + vec.z * cos(angle);
	}
	else if (axis == Y)
	{
		rotated.x = vec.x * cos(angle) + vec.z * sin(angle);
		rotated.z = -vec.x * sin(angle) + vec.z * cos(angle);
	}
	else if (axis == Z)
	{
		rotated.x = vec.x * cos(angle) - vec.y * sin(angle);
		rotated.y = vec.x * sin(angle) + vec.y * cos(angle);
	}
	return (vec3_normalize(rotated));
}
