/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:18:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 17:20:51 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int nc_intlen(int n)
{
	int		size;
	long	num;

	size = 1;
	num = n;
	if (n < 0)
	{
		num = -num;
		size++;
	}
	while (num >= 10)
	{
		num /= 10;
		size++;
	}
	return (size);
}

void	get_numbers(char *str, int *n1, int *n2, int *len)
{
	char 	*first_part;
	char 	*second_part;
	char	*tmp;
	
	tmp = nc_strchr(str, '.');
	*len = tmp - str;
	first_part = nc_substr(str, 0, *len);
	second_part = nc_substr(str, *len + 1, (nc_strlen(str) - *len));
	*n1 = nc_atoi(first_part);
	*n2 = nc_atoi(second_part);
	free(first_part);
	free(second_part);
	*len = nc_intlen(*n2);
}

float	ft_atof(char *str)
{
	float 	nbr;
	int 	n1;
	int 	n2;
	int		len;

	n1 = 0;
	n2 = 0;
	len = 0;
	get_numbers(str, &n1, &n2, &len);
	if (n1 > 0)
		nbr =  n1 + ((float) n2 / (float) pow(10, len));
	else
		nbr =  n1 - ((float) n2 / (float) pow(10, len));
	return (nbr);
}
