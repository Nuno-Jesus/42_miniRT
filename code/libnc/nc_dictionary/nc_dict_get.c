/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dict_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:07:28 by marvin            #+#    #+#             */
/*   Updated: 2023/05/14 19:07:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static void	*helper(t_bstree *tree, t_pair *tmp, int (*cmp)(void *, void *))
{
	void	*value;
	t_pair	*pair;

	if (!tree)
		return (NULL);
	pair = tree->data;
	if (!cmp(pair, tmp))
		return (pair);
	value = helper(tree->left, tmp, cmp);
	if (!value)
		value = helper(tree->right, tmp, cmp);
	return (value);
}

t_pair	*nc_dict_get(t_dict *dict, void *key)
{
	t_pair	*pair;
	t_pair	tmp;

	if (!dict || !key)
		return (NULL);
	tmp.key = key;
	pair = helper(dict->pairs, &tmp, dict->keycmp);
	return (pair);
}
