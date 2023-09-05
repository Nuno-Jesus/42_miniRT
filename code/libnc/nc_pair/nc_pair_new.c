/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_pair_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:25:51 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 14:25:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_pair	*nc_pair_new(void *first, void *second)
{
	t_pair	*pair;

	pair = nc_calloc(1, sizeof(t_pair));
	if (!pair)
		return (NULL);
	pair->key = first;
	pair->value = second;
	return (pair);
}
