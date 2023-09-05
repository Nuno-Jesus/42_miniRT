/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:08:41 by marvin            #+#    #+#             */
/*   Updated: 2023/05/17 21:08:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_vector_print(t_vector *vector)
{
	uint32_t	i;

	if (!vector)
		return ;
	i = -1;
	while (++i < vector->size)
		(*vector->print)(vector->array[i]);
}
