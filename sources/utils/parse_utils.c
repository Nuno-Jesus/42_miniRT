/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:39:48 by maricard          #+#    #+#             */
/*   Updated: 2023/07/04 17:18:47 by ncarvalh         ###   ########.fr       */
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

bool	parse_rgb(char **data)
{
	int	i;
	int	a;

	i = -1;
	while (data[++i])
	{
		a = -1;
		while (data[i][++a] && data[i][a] != '\n')
		{
			if (!nc_isdigit(data[i][a]))
			{
				nc_matrix_delete(data, &free);
				return (false);
			}
		}
		if (nc_atoi(data[i]) < 0 || nc_atoi(data[i]) > 255)
		{
			nc_matrix_delete(data, &free);
			return (false);
		}
	}
	return (true);
}
