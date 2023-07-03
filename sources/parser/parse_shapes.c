/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:11:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/03 17:20:40 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_plane(t_root *root, char **tokens)
{
	char	**point;
	char	**normal;
	char	**color;
	t_plane	*plane;
	
	parse_syntax(tokens, "0111");
	point = nc_split(tokens[1], ',');
	normal = nc_split(tokens[2], ',');
	color = nc_split(tokens[3], ',');
	plane = plane_new(point, normal, color);
	nc_vector_push(root->planes, plane);
	nc_matrix_delete(point, &free);
	nc_matrix_delete(normal, &free);
	nc_matrix_delete(color, &free);
	plane_debug(plane);
}

void	parse_sphere(t_root *root, char **tokens)
{
	parse_syntax(tokens, "0101");
	(void) root;
	(void) tokens;
}

void	parse_cylinder(t_root *root, char **tokens)
{
	parse_syntax(tokens, "011001");
	(void) root;
	(void) tokens;
}