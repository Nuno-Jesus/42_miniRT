/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:39:48 by maricard          #+#    #+#             */
/*   Updated: 2023/07/03 20:31:05 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

bool	parse_rgb(char **data)
{
	int i;
	int a;

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
