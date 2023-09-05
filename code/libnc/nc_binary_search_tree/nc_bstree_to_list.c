/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_bstree_to_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:12:55 by marvin            #+#    #+#             */
/*   Updated: 2023/05/14 12:12:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_list	*nc_bstree_to_list(t_bstree *tree, void *(*copy)(void *))
{
	t_list	*left;
	t_list	*right;

	left = NULL;
	if (!tree)
		return (NULL);
	left = nc_bstree_to_list(tree->left, copy);
	nc_list_add_back(&left, nc_list_new(copy(tree->data)));
	right = nc_bstree_to_list(tree->right, copy);
	nc_list_add_back(&left, right);
	return (left);
}
