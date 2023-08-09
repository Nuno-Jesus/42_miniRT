/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:18:19 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 20:14:05 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_syntax(char **tokens, char *code)
{
	int		i;
	bool	ok;
	int		numbers_size;
	char	**numbers;

	i = -1;
	ok = true;
	while (tokens[++i])
	{
		numbers = nc_split(tokens[i], ',');
		numbers_size = nc_matrix_size(numbers);
		if (code[i] == HAS_COMMAS)
			ok = (nc_count(tokens[i], ',') == 2 && numbers_size == 3);
		else
			ok = (nc_count(tokens[i], ',') == 0);
		if (!parse_double(numbers) && i > 0)
			ok = false;
		nc_matrix_delete(numbers, &free);
		if (!ok)
			return (false);
	}
	return (true);
}

bool	identifying(t_world *world, char **tokens)
{
	if (!nc_strncmp(tokens[0], "A", nc_strlen(tokens[0])))
		return (parse_ambient_light(world, tokens));
	else if (!nc_strncmp(tokens[0], "C", nc_strlen(tokens[0])))
		return (parse_camera(world, tokens));
	else if (!nc_strncmp(tokens[0], "L", nc_strlen(tokens[0])))
		return (parse_light_source(world, tokens));
	else if (!nc_strncmp(tokens[0], "pl", nc_strlen(tokens[0])))
		return (parse_plane(world, tokens));
	else if (!nc_strncmp(tokens[0], "sp", nc_strlen(tokens[0])))
		return (parse_sphere(world, tokens));
	else if (!nc_strncmp(tokens[0], "cy", nc_strlen(tokens[0])))
		return (parse_cylinder(world, tokens));
	else
		return (false);
	return (true);
}

void	parse_map(t_world *world, char **map)
{
	int		i;
	bool	ok;
	char	**tokens;

	i = -1;
	while (map[++i])
	{
		tokens = nc_split(map[i], ' ');
		ok = identifying(world, tokens);
		nc_matrix_delete(tokens, &free);
		if (!ok)
			message(world, ERROR_SYNTAX);
	}
}

t_world	*world_new(void)
{
	t_world	*world;

	world = nc_calloc(1, sizeof(t_world));
	if (!world)
		return (NULL);
	world->shapes = nc_vector_new((void *)&shape_copy, NULL, \
		&free, (void *)&shape_print);
	world->lights = nc_vector_new((void *)&light_copy, NULL, \
		&free, (void *)&light_print);
	return (world);
}

t_world	*parse(char *filename)
{
	t_world	*world;

	if (!is_filename_valid(filename))
		message(NULL, ERROR_FILENAME);
	world = world_new();
	if (!world)
		return (NULL); // Change this to message
	world->map = read_map(world, filename);
	if (nc_matrix_size(world->map) == 0)
		message(world, ERROR_EMPTY_MAP);
	parse_map(world, world->map);
	if (vec3_length(world->camera.normal) == 0)
		message(world, ERROR_NO_CAMERA);	
	return (world);
}
