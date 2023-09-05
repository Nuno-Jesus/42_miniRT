/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dict_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:40:51 by marvin            #+#    #+#             */
/*   Updated: 2023/05/15 13:40:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static t_list	*helper(t_bstree *tree, t_dict *dict)
{
	t_list	*left;
	t_list	*right;
	t_pair	*pair;

	left = NULL;
	if (!tree)
		return (NULL);
	pair = tree->data;
	left = helper(tree->left, dict);
	nc_list_add_back(&left, nc_list_new(dict->keycpy(pair->key)));
	right = helper(tree->right, dict);
	nc_list_add_back(&left, right);
	return (left);
}

t_list	*nc_dict_keys(t_dict *dict)
{
	t_list	*list;

	if (!dict || !dict->pairs)
		return (NULL);
	list = helper(dict->pairs, dict);
	return (list);
}
