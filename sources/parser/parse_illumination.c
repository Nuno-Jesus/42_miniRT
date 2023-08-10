/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:12:25 by maricard          #+#    #+#             */
/*   Updated: 2023/08/10 15:26:45 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_ambient_light(t_light *ambient, char **tokens)
{
	char	**cl;

	if (nc_matrix_size(tokens) != 3)
		return (false);
	if (!parse_syntax(tokens, "001"))
		return (false);
	if (!parse_rgb(tokens[2]))
		return (false);
	cl = nc_split(tokens[2], ',');
	ambient->ratio = nc_atof(tokens[1]);
	ambient->color = color_new(nc_atoi(cl[R]), nc_atoi(cl[G]), nc_atoi(cl[B]));
	nc_matrix_delete(cl, &free);
	return (true);
}

bool	parse_camera(t_camera *cam, char **tokens)
{
	char	**tmp;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0110"))
		return (false);
	tmp = nc_split(tokens[1], ',');
	cam->center = vec3_new(nc_atof(tmp[X]), nc_atof(tmp[Y]), nc_atof(tmp[Z]));
	nc_matrix_delete(tmp, &free);
	tmp = nc_split(tokens[2], ',');
	cam->normal = vec3_new(nc_atof(tmp[X]), nc_atof(tmp[Y]), nc_atof(tmp[Z]));
	nc_matrix_delete(tmp, &free);
	cam->normal = vec3_add(cam->normal, VEC_EPSILON);
	cam->normal = vec3_normalize(cam->normal);
	cam->fov = nc_atof(tokens[3]);
	return (true);
}

bool	parse_light_source(t_vector *lights, char **tokens)
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
	nc_vector_push(lights, light);
	nc_matrix_delete(origin, &free);
	nc_matrix_delete(color, &free);
	return (true);
}
