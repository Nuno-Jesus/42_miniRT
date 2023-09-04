/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:09:18 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/12 18:40:59 by ncarvalh         ###   ########.fr       */
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

int	get_filesize(t_world *world, char *filename)
{
	int		fd;
	int		counter;
	char	*line;

	counter = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(world, ERROR_OPEN_FILE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
			counter++;
		free(line);
	}
	close(fd);
	return (counter);
}

char	**read_map(t_world *world, char *filename)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	map = nc_matrix_new(get_filesize(world, filename), 0);
	if (!map)
		message(world, ERROR_MALLOC("read_map"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(world, ERROR_OPEN_FILE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!nc_strchr("\n#", line[0]))
			map[i++] = line;
		else
			free(line);
	}
	close(fd);
	return (map);
}
