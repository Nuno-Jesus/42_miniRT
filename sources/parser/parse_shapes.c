/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:11:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/13 16:26:50 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_plane(t_root *root, char **tokens)
{
	char	**point;
	char	**normal;
	char	**color;
	t_plane	plane;
	t_shape	*shape;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0111"))
		return (false);
	if (!parse_rgb(tokens[3]))
		return (false);
	point = nc_split(tokens[1], ',');
	normal = nc_split(tokens[2], ',');
	color = nc_split(tokens[3], ',');
	plane = plane_new(point, normal, color);
	shape = shape_new(&plane, PLANE);
	nc_vector_push(root->shapes, shape);
	nc_matrix_delete(point, &free);
	nc_matrix_delete(normal, &free);
	nc_matrix_delete(color, &free);
	plane_print(&plane);
	return (true);
}

bool	parse_sphere(t_root *root, char **tokens)
{
	char		**center;
	char		**color;
	t_sphere	sphere;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0101"))
		return (false);
	if (!parse_rgb(tokens[3]))
		return (false);
	center = nc_split(tokens[1], ',');
	color = nc_split(tokens[3], ',');
	sphere = sphere_new(center, tokens[2], color);
	shape = shape_new(&sphere, SPHERE);
	nc_vector_push(root->shapes, shape);
	nc_matrix_delete(center, &free);
	nc_matrix_delete(color, &free);
	sphere_print(&sphere);
	return (true);
}

bool	parse_cylinder(t_root *root, char **tokens)
{
	t_cylinder	cylinder;
	t_shape		*shape;

	if (nc_matrix_size(tokens) != 6)
		return (false);
	if (!parse_syntax(tokens, "011001"))
		return (false);
	if (!parse_rgb(tokens[5]))
		return (false);
	cylinder = cylinder_new(tokens);
	shape = shape_new(&cylinder, CYLINDER);
	nc_vector_push(root->shapes, shape);
	cylinder_print(&cylinder);
	return (true);
}
