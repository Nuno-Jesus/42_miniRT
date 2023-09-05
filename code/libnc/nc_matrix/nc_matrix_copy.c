/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:15:23 by marvin            #+#    #+#             */
/*   Updated: 2023/05/12 23:15:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_matrix_copy(void *matrix, void *(*copy)(void *))
{
	void	**res;
	size_t	i;

	res = nc_calloc(nc_matrix_size(matrix) + 1, sizeof(void *));
	if (!res)
		return (NULL);
	i = -1;
	while (((void **)matrix)[++i])
	{
		if (copy)
			res[i] = (*copy)(((void **)matrix)[i]);
		else
			res[i] = ((void **)matrix)[i];
	}
	return (res);
}
