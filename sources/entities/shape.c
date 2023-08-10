/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:32:09 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/10 17:40:07 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_shape	*shape_new(void	*data, t_shape_type type)
{
	t_shape	*shape;

	shape = nc_calloc(1, sizeof(t_shape));
	if (!shape)
		return (NULL);
	shape->type = type;
	if (type == PLANE)
		shape->data.pl = *(t_plane *)data;
	else if (type == SPHERE)
		shape->data.sp = *(t_sphere *)data;
	else if (type == CYLINDER)
		shape->data.cy = *(t_cylinder *)data;
	return (shape);
}

t_shape	*shape_copy(t_shape *shape)
{
	t_shape	*copy;

	copy = nc_calloc(1, sizeof(t_shape));
	if (!copy)
		return (NULL);
	copy->type = shape->type;
	if (shape->type == PLANE)
		copy->data.pl = shape->data.pl;
	else if (shape->type == SPHERE)
		copy->data.sp = shape->data.sp;
	else if (shape->type == CYLINDER)
		copy->data.cy = shape->data.cy;
	return (copy);
}
