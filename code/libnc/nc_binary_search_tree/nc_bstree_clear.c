/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_bstree_clear.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:21:20 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 18:21:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_bstree_clear(t_bstree *tree, void (*del)(void *))
{
	if (!tree)
		return ;
	nc_bstree_clear(tree->left, del);
	nc_bstree_clear(tree->right, del);
	nc_bstree_delete(tree, del);
}
