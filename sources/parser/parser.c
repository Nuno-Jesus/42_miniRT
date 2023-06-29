/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:18:19 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 17:13:48 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//bool	is_filename_valid(char *filename)
//{
//	size_t	len;

//	len = nc_strlen(filename);
//	if (len < 3)
//		return (false);
//	return (nc_strnstr(filename + (len - 3), ".rt", len) != NULL);
//}

//void	parse_line(t_root *root, char *line)
//{
//	(void)root;
//	(void)line;
//}

//t_root	*parse(char *filename)
//{
//	t_root	*root;
//	char	*line;
//	int		fd;
	
//	if (!is_filename_valid(filename))
//		message(NULL, "Invalid filename.");
//	root = nc_calloc(1, sizeof(t_root));
//	if (!root)
//		return (NULL);
//	fd = open(filename, O_RDONLY);
//	if (fd < 0)
//		message(root, "Error opening file.");
//	while (1)
//	{
//		line = get_next_line(fd);
//		if (!line)
//			break;
//		parse_line(root, line);
//		free(line);
//	}
//	return (root);
//}