/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:09:10 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/07 23:09:11 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_scale(t_vec3 v1, float scalar)
{
	t_vec3	res;

	res = vec3_new(v1.x * scalar, v1.y * scalar, v1.z * scalar);
	return (res);
}
