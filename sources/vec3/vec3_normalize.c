/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:08:56 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/07 23:08:57 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_normalize(t_vec3 vec)
{
	t_vec3	res;

	res.x = vec.x / vec3_module(vec);
	res.y = vec.y / vec3_module(vec);
	res.z = vec.z / vec3_module(vec);
	return (res);
}
