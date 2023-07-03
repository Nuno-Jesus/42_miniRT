/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:42:23 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 19:49:52 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (s)
		nc_putstr_fd(s, fd);
	nc_putchar_fd('\n', fd);
}
