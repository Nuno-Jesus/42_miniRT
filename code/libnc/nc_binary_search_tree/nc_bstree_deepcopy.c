/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_bstree_deepcopy.c                                :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:37:20 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 18:37:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_bstree	*nc_bstree_deepcopy(t_bstree *tree, void *(*copy)(void *))
{
	t_bstree	*dup;

	if (!tree)
		return (NULL);
	dup = nc_bstree_copy(tree, copy);
	dup->left = nc_bstree_deepcopy(tree->left, copy);
	dup->right = nc_bstree_deepcopy(tree->right, copy);
	return (dup);
}
