/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:18:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 17:00:43 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int nc_intlen(int number)
{
	int len;

	len = 0;
	while (number >)	
}

int		find_dot(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ".")
			return (i);
		i++;
	}
	return (0);
}

void	get_numbers(char *str, int *n1, int *n2)
{
	char 	*first_part;
	char 	*second_part;
	int 	len;

	len = find_dot(str);
	first_part = nc_substr(str, 0, len);
	second_part = nc_substr(str, len + 1, (nc_strlen(str) - len));
	*n1 = nc_itoa(first_part);
	*n2 = nc_itoa(second_part);
	free(first_part);
	free(second_part);
	get_length()
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
	
	return (nbr);
}
