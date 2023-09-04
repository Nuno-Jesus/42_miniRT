/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:12:25 by maricard          #+#    #+#             */
/*   Updated: 2023/08/14 16:48:29 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_ambient_light(t_light *ambient, char **tokens, int counters[3])
{
	char	**color;

	if (nc_matrix_size(tokens) != 3)
		return (ERROR("Wrong number of args in ambient (need 3)"), false);
	if (!parse_syntax(tokens, "001"))
		return (ERROR("Misconfiguration in commas/numbers in ambient"), false);
	if (!parse_rgb(tokens[2]))
		return (ERROR("Colors misformatting in ambient"), false);
	if (nc_atod(tokens[1]) < 0.0 || nc_atod(tokens[1]) > 1.0)
		return (ERROR("Ambient ratio out of bounds [0,1.0]"), false);
	color = nc_split(tokens[2], ',');
	ambient->ratio = nc_atod(tokens[1]);
	ambient->color = color_from_strings(color);
	nc_matrix_delete(color, &free);
	counters[0]++;
	return (true);
}

bool	parse_camera(t_camera *cam, char **tokens, int counters[3])
{
	char	**color;
	char	**normal;

	if (nc_matrix_size(tokens) != 4)
		return (ERROR("Wrong number of args in camera (need 4)"), false);
	if (!parse_syntax(tokens, "0110"))
		return (ERROR("Misconfiguration in commas/numbers in camera"), false);
	color = nc_split(tokens[1], ',');
	normal = nc_split(tokens[2], ',');
	cam->center = vec3_from_strings(color);
	cam->normal = vec3_from_strings(normal);
	cam->normal = vec3_add(cam->normal, VEC_EPSILON);
	nc_matrix_delete(color, &free);
	nc_matrix_delete(normal, &free);
	if (vec3_length(cam->normal) < 1.0 - EPSILON)
		return (ERROR("Normal vector is too small in camera"), false);
	cam->normal = vec3_normalize(cam->normal);
	cam->fov = nc_atod(tokens[3]);
	if (cam->fov < 0.0 || cam->fov > 180.0)
		return (ERROR("FOV out of bounds [0, 180]"), false);
	counters[1]++;
	return (true);
}

bool	parse_light_source(t_vector *lights, char **tokens, int counters[3])
{
	char	**origin;
	char	**color;
	t_light	*light;

	if (nc_matrix_size(tokens) != 4)
		return (ERROR("Wrong number of args in light (need 4)"), false);
	if (!parse_syntax(tokens, "0101"))
		return (ERROR("Misconfiguration in commas/numbers in light"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR("Colors misformatting in light"), false);
	if (nc_atod(tokens[2]) < 0.0 || nc_atod(tokens[2]) > 1.0)
		return (ERROR("Light brightness out of bounds [0,1.0]"), false);
	origin = nc_split(tokens[1], ',');
	color = nc_split(tokens[3], ',');
	light = light_new(origin, tokens[2], color);
	nc_vector_push(lights, light);
	nc_matrix_delete(origin, &free);
	nc_matrix_delete(color, &free);
	counters[2]++;
	return (true);
}
