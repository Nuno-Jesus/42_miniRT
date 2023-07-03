/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:11:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/03 13:22:22 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_plane(t_root *root, char **tokens)
{
	char	**point;
	char	**normal;
	char	**color;
	t_plane	plane;
	t_plane *tmp;
	
	parse_syntax(tokens, "0111");
	point = nc_split(tokens[1], ',');
	normal = nc_split(tokens[2], ',');
	color = nc_split(tokens[3], ',');
	plane = (t_plane)
	{
		.point.x = ft_atof(point[0]),
		.point.y = ft_atof(point[1]),
		.point.z = ft_atof(point[2]),
		.normal.x = ft_atof(normal[0]),
		.normal.y = ft_atof(normal[1]),
		.normal.z = ft_atof(normal[2]),
		.color.r = nc_atoi(color[0]),
		.color.g = nc_atoi(color[1]),
		.color.b = nc_atoi(color[2]),
	};
	nc_matrix_delete(point, &free);
	nc_matrix_delete(normal, &free);
	nc_matrix_delete(color, &free);
}

void	parse_sphere(t_root *root, char **tokens)
{
	parse_syntax(tokens, "0101");
	(void) root;
}

void	parse_cylinder(t_root *root, char **tokens)
{
	parse_syntax(tokens, "011001");
	(void) root;
	(void) tokens;
}