/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_bstree_delete.c                                  :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:52:01 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 17:52:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_bstree_delete(t_bstree *node, void (*del)(void *))
{
	if (!node)
		return ;
	if (*del)
		(*del)(node->data);
	free(node);
}
