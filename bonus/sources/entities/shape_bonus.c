/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:41:54 by marvin            #+#    #+#             */
/*   Updated: 2023/09/04 11:03:18 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_shape	*shape_new(void *data, t_shape_type type, int id, char **tokens)
{
	t_shape	*shape;

	shape = nc_calloc(1, sizeof(t_shape));
	if (!shape)
		return (NULL);
	if (type == PLANE)
		shape->data.pl = *(t_plane *)data;
	else if (type == SPHERE)
		shape->data.sp = *(t_sphere *)data;
	else if (type == CYLINDER)
		shape->data.cy = *(t_cylinder *)data;
	else if (type == CONE)
		shape->data.co = *(t_cone *)data;
	shape->id = id;
	shape->type = type;
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
