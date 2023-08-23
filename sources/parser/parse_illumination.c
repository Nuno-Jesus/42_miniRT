/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:12:25 by maricard          #+#    #+#             */
/*   Updated: 2023/08/18 18:28:11 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_ambient_light(t_light *ambient, char **tokens, int *counter)
{
	char	**color;

	if (nc_matrix_size(tokens) != 3)
		return (ERROR_NUM_ARGS("ambient", "3"), false);
	if (!parse_syntax(tokens, "001"))
		return (ERROR_NUM_COMMAS("ambient"), false);
	if (!parse_rgb(tokens[2]))
		return (ERROR_MISFORMAT_COLOR("ambient"), false);
	if (nc_atod(tokens[1]) < 0.0 || nc_atod(tokens[1]) > 1.0)
		return (ERROR_AMBIENT_RATIO_OUT_OF_BOUNDS, false);
	color = nc_split(tokens[2], ',');
	ambient->color = color_from_strings(color);
	ambient->ratio = nc_atod(tokens[1]);
	nc_matrix_delete(color, &free);
	(*counter)++;
	return (true);
}

bool	parse_camera(t_camera *cam, char **tokens, int *counter)
{
	char	**color;
	char	**normal;

	if (nc_matrix_size(tokens) != 4)
		return (ERROR_NUM_ARGS("camera", "4"), false);
	if (!parse_syntax(tokens, "0110"))
		return (ERROR_NUM_COMMAS("camera"), false);
	if (nc_atod(tokens[3]) < 0.0 || nc_atod(tokens[3]) > 180.0)
		return (ERROR_CAMERA_FOV_OUT_OF_BOUNDS, false);
	color = nc_split(tokens[1], ',');
	normal = nc_split(tokens[2], ',');
	cam->center = vec3_from_strings(color);
	cam->normal = vec3_from_strings(normal);
	cam->normal = vec3_add(cam->normal, VEC_EPSILON);
	cam->fov = nc_atod(tokens[3]);
	nc_matrix_delete(color, &free);
	nc_matrix_delete(normal, &free);
	if (vec3_length(cam->normal) < 1.0 - EPSILON)
		return (ERROR_VALUES_TOO_SMALL("camera"), false);
	cam->normal = vec3_normalize(cam->normal);
	(*counter)++;
	return (true);
}

bool	parse_light_source(t_vector *lights, char **tokens)
{
	char	**origin;
	char	**color;
	t_light	*light;

	if (nc_matrix_size(tokens) != 4)
		return (ERROR_NUM_ARGS("light source", "4"), false);
	if (!parse_syntax(tokens, "0101"))
		return (ERROR_NUM_COMMAS("light source"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR_MISFORMAT_COLOR("light source"), false);
	if (nc_atod(tokens[2]) < 0.0 || nc_atod(tokens[2]) > 1.0)
		return (ERROR_LIGHT_BRIGHTNESS_OUT_OF_BOUNDS, false);
	origin = nc_split(tokens[1], ',');
	color = nc_split(tokens[3], ',');
	light = light_new(origin, tokens[2], color);
	nc_vector_push(lights, light);
	nc_matrix_delete(origin, &free);
	nc_matrix_delete(color, &free);
	return (true);
}
