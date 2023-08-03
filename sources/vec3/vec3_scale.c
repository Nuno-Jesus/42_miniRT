/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:09:10 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/03 13:06:29 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_scale(t_vec3 v1, double scalar)
{
	t_vec3	res;

	res = vec3_new(v1.x * scalar, v1.y * scalar, v1.z * scalar);
	return (res);
}
