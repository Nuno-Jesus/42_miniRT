/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:37:34 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/18 15:03:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static int	nc_isspace(char c)
{
	return (c == '\f' || c == '\n'
		|| c == '\r' || c == '\t'
		|| c == '\v' || c == ' ');
}

int	nc_atoi(const char *nptr)
{
	int		i;
	int		res;
	int		signal;

	i = 0;
	res = 0;
	signal = 1;
	while (nc_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	while (nc_isdigit(nptr[i]))
		res = res * 10 + nptr[i++] - '0';
	return (signal * res);
}
