/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:46:06 by marvin            #+#    #+#             */
/*   Updated: 2023/05/17 20:46:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_vector_find(t_vector *vector, void *element)
{
	uint32_t	i;

	i = -1;
	while (++i < vector->size)
		if (!(*vector->cmp)(vector->array[i], element))
			return (element);
	return (NULL);
}
