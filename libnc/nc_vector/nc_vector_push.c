/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:07:59 by marvin            #+#    #+#             */
/*   Updated: 2023/05/17 20:07:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_vector_push(t_vector *vector, void *element)
{
	void	**matrix;

	if (!vector)
		return ;
	matrix = nc_matrix_append(vector->array, element, vector->cpy);
	nc_matrix_delete(vector->array, vector->del);
	vector->array = matrix;
	vector->size++;
}
