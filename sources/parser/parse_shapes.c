/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:11:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/03 20:29:26 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_plane(t_root *root, char **tokens)
{
	char	**point;
	char	**normal;
	char	**color;
	t_plane	*plane;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0111"))
		return (false);
	point = nc_split(tokens[1], ',');
	normal = nc_split(tokens[2], ',');
	color = nc_split(tokens[3], ',');
	plane = plane_new(point, normal, color);
	nc_vector_push(root->planes, plane);
	nc_matrix_delete(point, &free);
	nc_matrix_delete(normal, &free);
	nc_matrix_delete(color, &free);
	plane_print(plane);
	return (true);
}

bool	parse_sphere(t_root *root, char **tokens)
{
	char		**center;
	char		**color;
	t_sphere	*sphere;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0101"))
		return (false);
	center = nc_split(tokens[1], ',');
	color = nc_split(tokens[3], ',');
	sphere = sphere_new(center, tokens[2], color);
	nc_vector_push(root->spheres, sphere);
	nc_matrix_delete(center, &free);
	nc_matrix_delete(color, &free);
	sphere_print(sphere);
	return (true);
}

bool	parse_cylinder(t_root *root, char **tokens)
{
	char		**center;
	char		**normal;
	char		**color;
	t_cylinder	*cylinder;

	if (nc_matrix_size(tokens) != 6)
		return (false);
	if (!parse_syntax(tokens, "011001"))
		return (false);
	center = nc_split(tokens[1], ',');
	normal = nc_split(tokens[2], ',');
	color = nc_split(tokens[5], ',');
	cylinder = cylinder_new(center, normal, tokens[3], tokens[4], color);
	nc_vector_push(root->cylinders, cylinder);
	nc_matrix_delete(center, &free);
	nc_matrix_delete(normal, &free);
	nc_matrix_delete(color, &free);
	cylinder_print(cylinder);
	return (true);
}
