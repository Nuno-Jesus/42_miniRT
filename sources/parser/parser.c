/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:18:19 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/03 19:08:28 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_float(char **nb)
{
	int i;
	int a;

	i = -1;
	while (nb[++i])
	{
		a = 0;
		if (nb[i][a] == '-')
			a++;
		while (nb[i][a] && nb[i][a] != '.' && nb[i][a] != '\n')
		{
			if (!nc_isdigit(nb[i][a]))
				return (false);
			a++;
		}
		if (nb[i][a] == '.')
			a++;
		while (nb[i][a] && nb[i][a] != '\n')
		{
			if (!nc_isdigit(nb[i][a]))
				return (false);
			a++;
		}
	}
	return (true);
}

int	nc_count(char *str, char c)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (str[++i])
		if (str[i] == c)
			counter++;
	return (counter);
}

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
		if (code[i] == '1')
		{
			if (nc_count(tokens[i], ',') != 2 || numbers_size != 3)
				ok = false;
		}
		else
		{
			if (nc_count(tokens[i], ',') > 0)
				ok = false;
		}
		if (!parse_float(numbers) && i > 0)
			ok = false;
		nc_matrix_delete(numbers, &free);
		if (!ok)
			return (false);
	}
	return (true);
}

bool	identifying(t_root *root, char **tokens)
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

void	parse_map(t_root *root, char **map)
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
			message(root, "Syntax: file format misconfiguration.");
	}
}

t_root	*root_new(void)
{
	t_root	*root;

	root = nc_calloc(1, sizeof(t_root));
	if (!root)
		return (NULL);
	root->planes = nc_vector_new((void *)&plane_copy, NULL, &free, (void *)&plane_print);
	root->spheres = nc_vector_new((void *)&sphere_copy, NULL, &free, (void *)&sphere_print);
	root->cylinders = nc_vector_new((void *)&cylinder_copy, NULL, &free, (void *)&cylinder_print);
	root->sources = nc_vector_new((void *)&source_copy, NULL, &free, (void *)&source_print);
	return (root);
}

t_root	*parse(char *filename)
{
	t_root	*root;
	
	if (!is_filename_valid(filename))
		message(NULL, "Invalid filename.");
	root = root_new();
	if (!root)
		return (NULL);
	root->map = read_map(root, filename);
	if (nc_matrix_size(root->map) == 0)
	{
		nc_matrix_delete(root->map, &free);
		message(root, "Empty map.");
	}
	parse_map(root, root->map);
	return (root);
}
