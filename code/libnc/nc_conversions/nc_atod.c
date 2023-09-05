/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:31:32 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/12 16:39:51 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static long	power(int n, int power)
{
	long	res;

	res = n;
	while (power > 1)
	{
		res = res * n;
		power--;
	}
	return (res);
}

double	nc_atod(char *str)
{
	int			i;
	double		res;
	double		signal;

	i = 0;
	res = 0.0;
	signal = 1.0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (nc_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	str += i;
	res += (double)nc_atoi(str) / power(10, nc_strlen(str));
	return (signal * res);
}
