/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:18:19 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 18:01:48 by ncarvalh         ###   ########.fr       */
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

// void	parse_line(t_root *root, char *line)
// {
// 	char	*tokens	
// }

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
	printf("%s", line);
}

t_root	*parse(char *filename)
{
	t_root	*root;
	char	**contents;
	char	*line;
	int		fd;
	int		i;
	
	i = 0;
	if (!is_filename_valid(filename))
		message(NULL, "Invalid filename.");
	root = nc_calloc(1, sizeof(t_root));
	contents = (char **)nc_matrix_new(get_filesize(root, filename), 0);
	if (!root)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(root, "Error opening file.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line[0] != '\n')
			contents[i++] = line;
		else
			free(line);
	}
	close(fd);
	nc_matrix_print(contents, print);
	nc_matrix_delete(contents, &free);
	return (root);
}