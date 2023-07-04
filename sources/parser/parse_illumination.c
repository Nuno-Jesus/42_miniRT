/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:12:25 by maricard          #+#    #+#             */
/*   Updated: 2023/07/04 16:31:11 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_ambient_light(t_root *root, char **tokens)
{
	char 	**data;

	if (nc_matrix_size(tokens) != 3)
		return (false);
	if (!parse_syntax(tokens, "001"))
		return (false);
	root->ambient.ratio = nc_atof(tokens[1]);
	data = nc_split(tokens[2], ',');
	if (!parse_rgb(data))
		message(root, ERROR_COLOR_A);
	root->ambient.color.r = nc_atoi(data[0]);
	root->ambient.color.g = nc_atoi(data[1]);
	root->ambient.color.b = nc_atoi(data[2]);
	nc_matrix_delete(data, &free);
	ambient_print(&root->ambient);
	return (true);
}

bool	parse_camera(t_root *root, char **tokens)
{
	char	 **data;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0110"))
		return (false);
	data = nc_split(tokens[1], ',');
	root->camera.origin.x = nc_atof(data[0]);
	root->camera.origin.y = nc_atof(data[1]);
	root->camera.origin.z = nc_atof(data[2]);
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

t_lightsource	*light_new(char **origin, char *brightness, char **color)
{
	t_lightsource	*light;

	light = nc_calloc(1, sizeof(t_lightsource));
	if (!light)
		return (NULL);
	*light = (t_lightsource)
	{
		.origin.x = nc_atof(origin[0]),
		.origin.y = nc_atof(origin[1]),
		.origin.z = nc_atof(origin[2]),
		.brightness = nc_atof(brightness),
		.color.r = nc_atoi(color[0]),
		.color.g = nc_atoi(color[1]),
		.color.b = nc_atoi(color[2])
	};
	return (light);
}

bool	parse_light_source(t_root *root, char **tokens)
{
	char 	**origin;
	char 	**color;
	t_lightsource	*light;	
	
	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0101"))
		return (false);
	origin = nc_split(tokens[1], ',');
	color = nc_split(tokens[3], ',');
	light = light_new(origin, tokens[2], color);
	nc_vector_push(root->sources, light);
	if (!parse_rgb(color))
		message(root, ERROR_COLOR_L);
	nc_matrix_delete(origin, &free);
	nc_matrix_delete(color, &free);
	nc_vector_print(root->sources);
	return (true);
}

