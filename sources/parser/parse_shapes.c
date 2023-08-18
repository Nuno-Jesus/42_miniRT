/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:11:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/18 17:33:17 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_plane(t_vector *shapes, char **tokens)
{
	bool	ok;
	t_plane	plane;
	t_shape	*shape;

	if (nc_matrix_size(tokens) != 6)
		return (ERROR("Wrong number of args in plane (need 6)"), false);
	if (!parse_syntax(tokens, "011100"))
		return (ERROR("Misconfiguration in commas/numbers in plane"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR("Colors misformatting in plane"), false);
	if (nc_atod(tokens[4]) < 0.0 || nc_atod(tokens[4]) > 1.0)
		return (ERROR("Specular coefficient out of bounds in plane [0.0,1.0]"), false);
	if (nc_atod(tokens[5]) < 0.0)
		return (ERROR("Shininess out of bounds in plane [0.0, +∞["), false);
	ok = plane_from_strings(&plane, tokens);
	if (!ok)
		return (ERROR("Values are too small in plane"), false);
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
		return (ERROR("Wrong number of args in sphere (need 6)"), false);
	if (!parse_syntax(tokens, "010100"))
		return (ERROR("Misconfiguration in commas/numbers in sphere"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR("Colors misformatting in sphere"), false);
	if (nc_atod(tokens[4]) < 0.0 || nc_atod(tokens[4]) > 1.0)
		return (ERROR("Specular coefficient out of bounds in sphere [0.0,1.0]"), false);
	if (nc_atod(tokens[5]) < 0.0)
		return (ERROR("Shininess out of bounds in sphere [0.0, +∞["), false);
	ok = sphere_from_strings(&sphere, tokens);
	if (!ok)
		return (ERROR("Values are too small in sphere"), false);
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
		return (ERROR("Wrong number of args in cylinder (need 8)"), false);
	if (!parse_syntax(tokens, "01100100"))
		return (ERROR("Misconfiguration in commas/numbers in cylinder"), false);
	if (!parse_rgb(tokens[5]))
		return (ERROR("Colors misformatting in cylinder"), false);
	if (nc_atod(tokens[6]) < 0.0 || nc_atod(tokens[6]) > 1.0)
		return (ERROR("Specular coefficient out of bounds in cylinder [0.0,1.0]"), false);
	if (nc_atod(tokens[7]) < 0.0)
		return (ERROR("Shininess out of bounds in cylinder [0.0, +∞["), false);
	ok = cylinder_from_strings(&cylinder, tokens);
	if (!ok)
		return (ERROR("Values are too small in cylinder"), false);
	shape = shape_new(&cylinder, CYLINDER, shapes->size, tokens + 6);
	nc_vector_push(shapes, shape);
	return (true);
}
