/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:23:08 by marvin            #+#    #+#             */
/*   Updated: 2023/05/17 20:23:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_vector_pop(t_vector *vector)
{
	if (!vector || !vector->size)
		return ;
	if (vector->del)
		(*vector->del)(vector->array[vector->size - 1]);
	vector->array[vector->size - 1] = NULL;
	--vector->size;
}
