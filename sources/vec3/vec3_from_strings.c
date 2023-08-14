/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_from_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:07:54 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/14 13:08:46 by ncarvalh         ###   ########.fr       */
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