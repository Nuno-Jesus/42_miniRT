/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:33:24 by marvin            #+#    #+#             */
/*   Updated: 2023/05/12 23:33:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_matrix_print(void *matrix, void (*print)(void *, size_t))
{
	size_t	i;

	i = -1;
	while (((void **)matrix)[++i])
		(*print)(((void **)matrix)[i], i);
	nc_putstr_fd("matrix[", STDOUT_FILENO);
	nc_putnbr_fd(i, STDOUT_FILENO);
	nc_putendl_fd("]=NULL", STDOUT_FILENO);
}
