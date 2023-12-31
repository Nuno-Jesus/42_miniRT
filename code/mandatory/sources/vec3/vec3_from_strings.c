/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_from_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:07:54 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/14 16:52:29 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_from_strings(char **vec)
{
	return ((t_vec3)
		{
			.x = nc_atod(vec[X]),
			.y = nc_atod(vec[Y]),
			.z = nc_atod(vec[Z]),
		}
	);
}
