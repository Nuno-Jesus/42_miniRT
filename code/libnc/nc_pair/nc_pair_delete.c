/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_pair_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:03:53 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 15:03:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_pair_delete(t_pair *pair, void (*keydel)(void *), \
	void (*valdel)(void *))
{
	if (!pair)
		return ;
	nc_pair_clear(pair, keydel, valdel);
	free(pair);
}
