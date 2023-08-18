/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:11:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/18 17:59:48 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_plane(t_vector *shapes, char **tokens)
{
	bool	ok;
	t_plane	plane;
	t_shape	*shape;

	if (nc_matrix_size(tokens) != 6)
		return (ERROR_NUM_ARGS("plane", "6"), false);
	if (!parse_syntax(tokens, "011100"))
		return (ERROR_NUM_COMMAS("plane"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR_MISFORMAT_COLOR("plane"), false);
	if (nc_atod(tokens[4]) < 0.0 || nc_atod(tokens[4]) > 1.0)
		return (ERROR_SPECULAR("plane"), false);
	if (nc_atod(tokens[5]) < 0.0)
		return (ERROR_SHININESS("plane"), false);
	ok = plane_from_strings(&plane, tokens);
	if (!ok)
		return (ERROR_VALUES_TOO_SMALL("plane"), false);
	shape = shape_new(&plane, PLANE, shapes->size, tokens + 4);
	nc_vector_push(shapes, shape);
	return (true);
}

bool	parse_sphere(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_sphere	sphere;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 6)
		return (ERROR_NUM_ARGS("sphere", "6"), false);
	if (!parse_syntax(tokens, "010100"))
		return (ERROR_NUM_COMMAS("sphere"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR_MISFORMAT_COLOR("sphere"), false);
	if (nc_atod(tokens[4]) < 0.0 || nc_atod(tokens[4]) > 1.0)
		return (ERROR_SPECULAR("sphere"), false);
	if (nc_atod(tokens[5]) < 0.0)
		return (ERROR_SHININESS("sphere"), false);
	ok = sphere_from_strings(&sphere, tokens);
	if (!ok)
		return (ERROR_VALUES_TOO_SMALL("plane"), false);
	shape = shape_new(&sphere, SPHERE, shapes->size, tokens + 4);
	nc_vector_push(shapes, shape);
	return (true);
}

bool	parse_cylinder(t_vector *shapes, char **tokens)
{
	bool		ok;
	t_cylinder	cylinder;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 8)
		return (ERROR_NUM_ARGS("cylinder", "8"), false);
	if (!parse_syntax(tokens, "01100100"))
		return (ERROR_NUM_COMMAS("cylinder"), false);
	if (!parse_rgb(tokens[5]))
		return (ERROR_MISFORMAT_COLOR("cylinder"), false);
	if (nc_atod(tokens[6]) < 0.0 || nc_atod(tokens[6]) > 1.0)
		return (ERROR_SPECULAR("cylinder"), false);
	if (nc_atod(tokens[7]) < 0.0)
		return (ERROR_SHININESS("cylinder"), false);
	ok = cylinder_from_strings(&cylinder, tokens);
	if (!ok)
		return (ERROR_VALUES_TOO_SMALL("plane"), false);
	shape = shape_new(&cylinder, CYLINDER, shapes->size, tokens + 6);
	nc_vector_push(shapes, shape);
	return (true);
}
