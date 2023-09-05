/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dict_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:43:48 by marvin            #+#    #+#             */
/*   Updated: 2023/05/14 18:43:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static t_bstree	*helper(t_bstree *tree, void *(*keycpy)(void *), \
	void *(*valcpy)(void *))
{
	t_bstree	*node;
	t_pair		*pair;

	if (!tree)
		return (NULL);
	pair = tree->data;
	node = nc_bstree_new(nc_pair_copy(pair, keycpy, valcpy), 0);
	node->left = helper(tree->left, keycpy, valcpy);
	node->right = helper(tree->right, keycpy, valcpy);
	return (node);
}

t_dict	*nc_dict_copy(t_dict *dict)
{
	t_dict	*copy;

	copy = nc_dict_new(dict->keycmp, dict->keycpy, dict->keydel, dict->keystr);
	nc_dict_values_setup(copy, dict->valcpy, dict->valdel, dict->valstr);
	if (!copy)
		return (NULL);
	copy->pairs = helper(dict->pairs, dict->keycpy, dict->valcpy);
	return (copy);
}
