/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:12:25 by maricard          #+#    #+#             */
/*   Updated: 2023/08/13 21:12:41 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_ambient_light(t_light *ambient, char **tokens, int counters[3])
{
	char	**cl;

	if (nc_matrix_size(tokens) != 3)
		return (false);
	if (!parse_syntax(tokens, "001"))
		return (false);
	if (!parse_rgb(tokens[2]))
		return (false);
	if (nc_atod(tokens[1]) < 0.0 || nc_atod(tokens[1]) > 1.0)
		return (false);
	cl = nc_split(tokens[2], ',');
	ambient->ratio = nc_atod(tokens[1]);
	ambient->color = color_new(nc_atoi(cl[R]), nc_atoi(cl[G]), nc_atoi(cl[B]));
	nc_matrix_delete(cl, &free);
	counters[0]++;
	return (true);
}

bool	parse_camera(t_camera *cam, char **tokens, int counters[3])
{
	char	**tmp;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0110"))
		return (false);
	tmp = nc_split(tokens[1], ',');
	cam->center = vec3_new(nc_atod(tmp[X]), nc_atod(tmp[Y]), nc_atod(tmp[Z]));
	nc_matrix_delete(tmp, &free);
	tmp = nc_split(tokens[2], ',');
	cam->normal = vec3_new(nc_atod(tmp[X]), nc_atod(tmp[Y]), nc_atod(tmp[Z]));
	nc_matrix_delete(tmp, &free);
	cam->normal = vec3_add(cam->normal, VEC_EPSILON);
	cam->normal = vec3_normalize(cam->normal);
	cam->fov = nc_atod(tokens[3]);
	counters[1]++;
	return (true);
}

bool	parse_light_source(t_vector *lights, char **tokens, int counters[3])
{
	char	**origin;
	char	**color;
	t_light	*light;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0101"))
		return (false);
	if (!parse_rgb(tokens[3]))
		return (false);
	if (nc_atod(tokens[2]) < 0.0 || nc_atod(tokens[2]) > 1.0)
		return (false);
	origin = nc_split(tokens[1], ',');
	color = nc_split(tokens[3], ',');
	light = light_new(origin, tokens[2], color);
	nc_vector_push(lights, light);
	nc_matrix_delete(origin, &free);
	nc_matrix_delete(color, &free);
	counters[2]++;
	return (true);
}
