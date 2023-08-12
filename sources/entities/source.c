/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:25:05 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/12 16:19:13 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_light	*light_new(char **c, char *ratio, char **cl)
{
	t_light	*bulb;

	bulb = nc_calloc(1, sizeof(t_light));
	if (!bulb)
		return (NULL);
	*bulb = (t_light)
	{
		.center = vec3_new(nc_atod(c[X]), nc_atod(c[Y]), nc_atod(c[Z])), 
		.ratio = nc_atod(ratio),
		.color = color_new(nc_atod(cl[R]), nc_atod(cl[G]), nc_atod(cl[B])), 
	};
	return (bulb);
}

t_light	*light_copy(t_light *bulb)
{
	t_light	*copy;

	copy = nc_calloc(1, sizeof(t_light));
	if (!copy)
		return (NULL);
	*copy = *bulb;
	return (copy);
}
