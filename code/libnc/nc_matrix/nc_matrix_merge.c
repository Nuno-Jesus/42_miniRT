/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:56:29 by marvin            #+#    #+#             */
/*   Updated: 2023/05/17 20:56:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	**nc_matrix_merge(void **m1, void **m2, void *(*copy)(void *))
{
	void		**matrix;
	uint32_t	first;
	uint32_t	second;
	uint32_t	i;

	first = nc_matrix_size(m1);
	second = nc_matrix_size(m2);
	matrix = nc_matrix_new(first + second, 0);
	if (!matrix)
		return (NULL);
	i = -1;
	if (copy)
		while (++i < first)
			matrix[i] = (*copy)(m1[i]);
	else
		while (++i < first)
			matrix[i] = m1[i];
	i = -1;
	if (copy)
		while (++i < second)
			matrix[i + first] = (*copy)(m2[i]);
	else
		while (++i < second)
			matrix[i + first] = m2[i];
	return (matrix);
}
