/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_pair_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:27:50 by marvin            #+#    #+#             */
/*   Updated: 2023/05/15 11:27:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_pair_clear(t_pair *pair, void (*keydel)(void *), \
	void (*valdel)(void *))
{
	if (!pair)
		return ;
	if (keydel && pair->key)
		keydel(pair->key);
	if (valdel && pair->value)
		valdel(pair->value);
}
