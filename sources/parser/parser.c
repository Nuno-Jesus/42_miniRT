/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:18:19 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 16:58:25 by ncarvalh         ###   ########.fr       */
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

t_root	*parse(char *filename)
{
	t_root	*root;
	
	if (!is_filename_valid(filename))
		message(NULL, "Invalid filename.");
	root = nc_calloc(1, sizeof(t_root));
	if (!root)
		return (NULL);
	return (root);
}