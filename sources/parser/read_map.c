/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:09:18 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/30 16:08:03 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_filename_valid(char *filename)
{
	size_t	len;

	len = nc_strlen(filename);
	if (len < 3)
		return (false);
	return (nc_strnstr(filename + (len - 3), ".rt", len) != NULL);
}

int	get_filesize(t_root *root, char *filename)
{
	int	fd;
	int counter;
	char *line;

	counter = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(root, "Error opening file.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line[0] != '\n')
			counter++;
		free(line);
	}
	close(fd);
	return (counter);
}

void	print(char *line)
{
	printf("%s\n", line);
}

char	**read_map(t_root *root, char *filename)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	map = (char **)nc_matrix_new(get_filesize(root, filename), 0);
	if (!map)
		message(root, "Failed allocation on read_map.");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(root, "Error opening file.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line[0] != '\n')
			map[i++] = line;
		else
			free(line);
	}
	close(fd);
	//nc_matrix_print(map, print);
	return (map);
}