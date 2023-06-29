/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:02:00 by marvin            #+#    #+#             */
/*   Updated: 2023/05/12 23:02:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_matrix_delete(void *matrix, void (*del)())
{
	size_t	i;

	i = -1;
	while (((void **)matrix)[++i])
		del(((void **)matrix)[i]);
	free(matrix);
}
