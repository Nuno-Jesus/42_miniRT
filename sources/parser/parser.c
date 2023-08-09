/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:18:19 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 19:22:16 by crypto           ###   ########.fr       */
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

bool	identifying(t_world *root, char **tokens)
{
	if (!nc_strncmp(tokens[0], "A", nc_strlen(tokens[0])))
		return (parse_ambient_light(root, tokens));
	else if (!nc_strncmp(tokens[0], "C", nc_strlen(tokens[0])))
		return (parse_camera(root, tokens));
	else if (!nc_strncmp(tokens[0], "L", nc_strlen(tokens[0])))
		return (parse_light_source(root, tokens));
	else if (!nc_strncmp(tokens[0], "pl", nc_strlen(tokens[0])))
		return (parse_plane(root, tokens));
	else if (!nc_strncmp(tokens[0], "sp", nc_strlen(tokens[0])))
		return (parse_sphere(root, tokens));
	else if (!nc_strncmp(tokens[0], "cy", nc_strlen(tokens[0])))
		return (parse_cylinder(root, tokens));
	else
		return (false);
	return (true);
}

void	parse_map(t_world *root, char **map)
{
	int		i;
	bool	ok;
	char	**tokens;

	i = -1;
	while (map[++i])
	{
		tokens = nc_split(map[i], ' ');
		ok = identifying(root, tokens);
		nc_matrix_delete(tokens, &free);
		if (!ok)
			message(root, ERROR_SYNTAX);
	}
}

t_world	*root_new(void)
{
	t_world	*root;

	root = nc_calloc(1, sizeof(t_world));
	if (!root)
		return (NULL);
	root->shapes = nc_vector_new((void *)&shape_copy, NULL, \
		&free, (void *)&shape_print);
	root->sources = nc_vector_new((void *)&source_copy, NULL, \
		&free, (void *)&source_print);
	return (root);
}

t_world	*parse(char *filename)
{
	t_world	*root;

	if (!is_filename_valid(filename))
		message(NULL, ERROR_FILENAME);
	root = root_new();
	if (!root)
		return (NULL); // Change this to message
	root->map = read_map(root, filename);
	if (nc_matrix_size(root->map) == 0)
		message(root, ERROR_EMPTY_MAP);
	parse_map(root, root->map);
	if (vec3_module(root->camera.normal) == 0)
		message(root, ERROR_NO_CAMERA);	
	return (root);
}
