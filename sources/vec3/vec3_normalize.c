/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:08:56 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 20:14:05 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_normalize(t_vec3 vec)
{
	t_vec3	res;

	res.x = vec.x / vec3_length(vec);
	res.y = vec.y / vec3_length(vec);
	res.z = vec.z / vec3_length(vec);
	return (res);
}
