/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dict_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:02:39 by marvin            #+#    #+#             */
/*   Updated: 2023/05/15 13:02:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static t_pair	*copy(t_pair *pair, t_dict *dict)
{
	t_pair	*dup;

	dup = nc_pair_copy(pair, dict->keycpy, dict->valcpy);
	if (!dup)
		return (NULL);
	return (dup);
}

static t_list	*helper(t_bstree *tree, t_dict *dict)
{
	t_list	*left;
	t_list	*right;

	left = NULL;
	if (!tree)
		return (NULL);
	left = helper(tree->left, dict);
	nc_list_add_back(&left, nc_list_new(copy(tree->data, dict)));
	right = helper(tree->right, dict);
	nc_list_add_back(&left, right);
	return (left);
}

t_list	*nc_dict_to_list(t_dict *dict)
{
	t_list	*list;

	if (!dict || !dict->pairs)
		return (NULL);
	list = helper(dict->pairs, dict);
	return (list);
}
