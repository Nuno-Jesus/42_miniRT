/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:06:56 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 15:08:10 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vector_norm(t_vec3 vec)
{
	t_vec3	res;

	res.x = vec.x / vector_mod(vec);
	res.y = vec.y / vector_mod(vec);
	res.z = vec.z / vector_mod(vec);
	return (res);
}