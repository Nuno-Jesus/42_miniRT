/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:43:28 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/05/18 15:03:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (fd < 0)
		return ;
	if (num < 0)
	{
		nc_putchar_fd('-', fd);
		num = -num;
	}
	if (num < 10)
		nc_putchar_fd(nc_tochar(num), fd);
	else
	{
		nc_putnbr_fd(num / 10, fd);
		nc_putchar_fd(nc_tochar(num % 10), fd);
	}
}
