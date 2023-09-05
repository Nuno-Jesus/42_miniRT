/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:05:31 by marvin            #+#    #+#             */
/*   Updated: 2023/05/17 20:05:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_vector	*nc_vector_new(void *(*cpy)(), int (*cmp)(void *, void *), \
	void (*del)(void *), void (*print)(void *))
{
	t_vector	*vector;

	vector = nc_calloc(1, sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->array = nc_calloc(1, sizeof(void *));
	if (!vector->array)
	{
		free(vector);
		return (NULL);
	}
	vector->cpy = cpy;
	vector->cmp = cmp;
	vector->del = del;
	vector->print = print;
	return (vector);
}
