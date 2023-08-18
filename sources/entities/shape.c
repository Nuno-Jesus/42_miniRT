/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:32:09 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/18 17:21:12 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_shape	*shape_new(void	*data, t_shape_type type, int id, char **tokens)
{
	t_shape	*shape;

	shape = nc_calloc(1, sizeof(t_shape));
	if (!shape)
		return (NULL);
	shape->id = id;
	shape->type = type;
	if (type == PLANE)
		shape->data.pl = *(t_plane *)data;
	else if (type == SPHERE)
		shape->data.sp = *(t_sphere *)data;
	else if (type == CYLINDER)
		shape->data.cy = *(t_cylinder *)data;
	shape->ks = nc_atod(tokens[0]);
	shape->shininess = nc_atod(tokens[1]);
	return (shape);
}

t_shape	*shape_copy(t_shape *shape)
{
	t_shape	*copy;

	copy = nc_calloc(1, sizeof(t_shape));
	if (!copy)
		return (NULL);
	*copy = *shape;
	return (copy);
}
