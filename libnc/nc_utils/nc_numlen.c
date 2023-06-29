/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:53:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 19:57:00 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

int	nc_numlen(int n)
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
