/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:12:25 by maricard          #+#    #+#             */
/*   Updated: 2023/08/09 19:22:16 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_ambient_light(t_world *root, char **tokens)
{
	char	**data;

	if (nc_matrix_size(tokens) != 3)
		return (false);
	if (!parse_syntax(tokens, "001"))
		return (false);
	if (!parse_rgb(tokens[2]))
		return (false);
	root->ambient.ratio = nc_atof(tokens[1]);
	data = nc_split(tokens[2], ',');
	root->ambient.color.r = nc_atoi(data[0]);
	root->ambient.color.g = nc_atoi(data[1]);
	root->ambient.color.b = nc_atoi(data[2]);
	nc_matrix_delete(data, &free);
	ambient_print(&root->ambient);
	return (true);
}

bool	parse_camera(t_world *root, char **tokens)
{
	char	**data;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0110"))
		return (false);
	data = nc_split(tokens[1], ',');
	root->camera.center.x = nc_atof(data[0]);
	root->camera.center.y = nc_atof(data[1]);
	root->camera.center.z = nc_atof(data[2]);
	nc_matrix_delete(data, &free);
	data = nc_split(tokens[2], ',');
	root->camera.normal.x = nc_atof(data[0]);
	root->camera.normal.y = nc_atof(data[1]);
	root->camera.normal.z = nc_atof(data[2]);
	root->camera.fov = nc_atof(tokens[3]);
	nc_matrix_delete(data, &free);
	camera_print(&root->camera);
	return (true);
}

t_light	*light_new(char **origin, char *ratio, char **color)
{
	t_light	*light;

	light = nc_calloc(1, sizeof(t_light));
	if (!light)
		return (NULL);
	*light = (t_light)
	{
		.center.x = nc_atof(origin[0]),
		.center.y = nc_atof(origin[1]),
		.center.z = nc_atof(origin[2]),
		.ratio = nc_atof(ratio),
		.color.r = nc_atoi(color[0]),
		.color.g = nc_atoi(color[1]),
		.color.b = nc_atoi(color[2])
	};
	return (light);
}

bool	parse_light_source(t_world *root, char **tokens)
{
	char			**origin;
	char			**color;
	t_light	*light;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0101"))
		return (false);
	if (!parse_rgb(tokens[3]))
		return (false);
	origin = nc_split(tokens[1], ',');
	color = nc_split(tokens[3], ',');
	light = light_new(origin, tokens[2], color);
	nc_vector_push(root->sources, light);
	nc_matrix_delete(origin, &free);
	nc_matrix_delete(color, &free);
	nc_vector_print(root->sources);
	return (true);
}
