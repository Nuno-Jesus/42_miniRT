/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:23:04 by marvin            #+#    #+#             */
/*   Updated: 2023/05/12 23:23:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_matrix_append(void *matrix, void *data, void *(*copy)(void *))
{
	void	**res;
	size_t	i;

	i = -1;
	res = nc_calloc(nc_matrix_size(matrix) + 2, sizeof(void *));
	while (((void **)matrix)[++i])
	{
		if (copy)
			res[i] = (*copy)(((void **)matrix)[i]);
		else
			res[i] = ((void **)matrix)[i];
	}
	res[i] = data;
	return (res);
}
