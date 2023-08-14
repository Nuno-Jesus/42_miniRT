/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:39:48 by maricard          #+#    #+#             */
/*   Updated: 2023/08/14 17:08:38 by crypto           ###   ########.fr       */
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

bool	parse_double(char **nb)
{
	int		i;
	char	*tmp;

	i = -1;
	while (nb[++i])
	{
		if (!nc_isnum(nb[i], ".\n") || nc_strclen(nb[i], ".") == 0)
			return (false);
		tmp = nc_strchr(nb[i], '.');
		if (tmp && (*(tmp + 1) == '\0' || !nc_isnum(tmp + 1, "\n")))
			return (false);
	}
	return (true);
}

bool	parse_rgb(char *color)
{
	int		i;
	bool	ok;
	char	**tokens;

	i = -1;
	ok = true;
	tokens = nc_split(color, ',');
	if (!tokens)
		return (false);
	while (tokens[++i])
	{
		if (!nc_isnum(tokens[i], "\n"))
			ok = false;
		if (nc_atoi(tokens[i]) < 0 || nc_atoi(tokens[i]) > 255)
			ok = false;
		if (!ok)
			break ;
	}
	nc_matrix_delete(tokens, &free);
	return (ok);
}
