/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:11:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/11 22:45:00 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_plane(t_vector *shapes, char **tokens)
{
	t_plane	plane;
	t_shape	*shape;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0111"))
		return (false);
	if (!parse_rgb(tokens[3]))
		return (false);
	plane = plane_from_strings(tokens);
	shape = shape_new(&plane, PLANE);
	shape->id = shapes->size;
	printf("shapes->id = %u\n", shape->id);
	nc_vector_push(shapes, shape);
	return (true);
}

bool	parse_sphere(t_vector *shapes, char **tokens)
{
	t_sphere	sphere;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0101"))
		return (false);
	if (!parse_rgb(tokens[3]))
		return (false);
	sphere = sphere_from_strings(tokens);
	shape = shape_new(&sphere, SPHERE);
	shape->id = shapes->size;
	printf("shapes->id = %u\n", shape->id);
	nc_vector_push(shapes, shape);
	return (true);
}

bool	parse_cylinder(t_vector *shapes, char **tokens)
{
	t_cylinder	cylinder;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 6)
		return (false);
	if (!parse_syntax(tokens, "011001"))
		return (false);
	if (!parse_rgb(tokens[5]))
		return (false);
	cylinder = cylinder_from_strings(tokens);
	shape = shape_new(&cylinder, CYLINDER);
	shape->id = shapes->size;
	printf("shapes->id = %u\n", shape->id);
	nc_vector_push(shapes, shape);
	return (true);
}
