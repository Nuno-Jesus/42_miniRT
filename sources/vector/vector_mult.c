/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:24:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/04 17:27:10 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vector_mult(t_vec3 v1, float scalar)
{
	t_vec3	res;

	res = vector_new(v1.x * scalar, v1.y * scalar, v1.z * scalar);
	return (res);
}
