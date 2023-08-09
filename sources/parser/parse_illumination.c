/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:12:25 by maricard          #+#    #+#             */
/*   Updated: 2023/08/09 20:12:46 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_ambient_light(t_world *world, char **tokens)
{
	char	**data;

	if (nc_matrix_size(tokens) != 3)
		return (false);
	if (!parse_syntax(tokens, "001"))
		return (false);
	if (!parse_rgb(tokens[2]))
		return (false);
	world->ambient.ratio = nc_atof(tokens[1]);
	data = nc_split(tokens[2], ',');
	world->ambient.color.r = nc_atoi(data[0]);
	world->ambient.color.g = nc_atoi(data[1]);
	world->ambient.color.b = nc_atoi(data[2]);
	nc_matrix_delete(data, &free);
	ambient_print(&world->ambient);
	return (true);
}

bool	parse_camera(t_world *world, char **tokens)
{
	char	**data;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0110"))
		return (false);
	data = nc_split(tokens[1], ',');
	world->camera.center.x = nc_atof(data[0]);
	world->camera.center.y = nc_atof(data[1]);
	world->camera.center.z = nc_atof(data[2]);
	nc_matrix_delete(data, &free);
	data = nc_split(tokens[2], ',');
	world->camera.normal.x = nc_atof(data[0]);
	world->camera.normal.y = nc_atof(data[1]);
	world->camera.normal.z = nc_atof(data[2]);
	world->camera.fov = nc_atof(tokens[3]);
	nc_matrix_delete(data, &free);
	camera_print(&world->camera);
	return (true);
}

bool	parse_light_source(t_world *world, char **tokens)
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
	nc_vector_push(world->lights, light);
	nc_matrix_delete(origin, &free);
	nc_matrix_delete(color, &free);
	nc_vector_print(world->lights);
	return (true);
}
