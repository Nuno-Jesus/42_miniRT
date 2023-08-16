/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:32:09 by ncarvalh          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/22 18:32:08 by marvin           ###   ########.fr       */
=======
/*   Updated: 2023/08/16 12:24:13 by maricard         ###   ########.fr       */
>>>>>>> acad2b5... code: cone ongoing
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
<<<<<<< HEAD
	shape->ks = nc_atod(tokens[0]);
	shape->shininess = nc_atod(tokens[1]);
	else if (type == TORUS)
		shape->data.to = *(t_torus *)data;
=======
	else if (type == CONE)
		shape->data.co = *(t_cone *)data;
>>>>>>> acad2b5... code: cone ongoing
	return (shape);
}

t_shape	*shape_copy(t_shape *shape)
{
	t_shape	*copy;

	copy = nc_calloc(1, sizeof(t_shape));
	if (!copy)
		return (NULL);
<<<<<<< HEAD
	*copy = *shape;
=======
	copy->id = shape->id;
	copy->type = shape->type;
	if (shape->type == PLANE)
		copy->data.pl = shape->data.pl;
	else if (shape->type == SPHERE)
		copy->data.sp = shape->data.sp;
	else if (shape->type == CYLINDER)
		copy->data.cy = shape->data.cy;
	else if (shape->type == CONE)
		copy->data.co = shape->data.co;
>>>>>>> acad2b5... code: cone ongoing
	return (copy);
}
