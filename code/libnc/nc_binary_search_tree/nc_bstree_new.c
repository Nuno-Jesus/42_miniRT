/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_bstree_new.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:08:47 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 17:08:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_bstree	*nc_bstree_new(void *data, uint32_t depth)
{
	t_bstree	*node;

	node = nc_calloc(1, sizeof(t_bstree));
	if (!node)
		return (NULL);
	node->data = data;
	node->depth = depth;
	return (node);
}
