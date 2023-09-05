/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dict_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:49:44 by marvin            #+#    #+#             */
/*   Updated: 2023/05/14 19:49:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static void	delete(t_dict *dict, t_bstree **node)
{
	nc_pair_delete((*node)->data, dict->keydel, dict->valdel);
	free((*node));
	*node = NULL;
}

static t_bstree	*find_best(t_bstree *tree)
{
	t_bstree	*curr;

	curr = tree;
	while (curr && curr->left)
		curr = curr->left;
	return (curr);
}

static t_bstree	*helper(t_bstree **tree, t_pair *pair, t_dict *dict)
{
	t_bstree	*node;

	if (dict->keycmp(pair, (*tree)->data) < 0)
		(*tree)->left = helper(&(*tree)->left, pair, dict);
	else if (dict->keycmp(pair, (*tree)->data) > 0)
		(*tree)->right = helper(&(*tree)->right, pair, dict);
	else
	{
		dict->size--;
		if (!(*tree)->left)
			node = (*tree)->right;
		else if (!(*tree)->right)
			node = (*tree)->left;
		if (!(*tree)->left || !(*tree)->right)
		{
			delete(dict, tree);
			return (node);
		}
		node = find_best((*tree)->right);
		nc_pair_delete((*tree)->data, dict->keydel, dict->valdel);
		(*tree)->data = nc_pair_copy(node->data, dict->keycpy, dict->valcpy);
		(*tree)->right = helper(&(*tree)->right, node->data, dict);
	}
	return (*tree);
}

void	nc_dict_remove(t_dict *dict, void *key)
{
	t_pair	tmp;

	if (!key || !dict || !dict->pairs)
		return ;
	tmp.key = key;
	dict->pairs = helper(&dict->pairs, &tmp, dict);
}
