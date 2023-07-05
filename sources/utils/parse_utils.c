/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:39:48 by maricard          #+#    #+#             */
/*   Updated: 2023/07/05 11:03:03 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_float(char **nb)
{
	int	i;
	int	a;

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
			break;
	}
	nc_matrix_delete(tokens, &free);
	return (ok);
}
