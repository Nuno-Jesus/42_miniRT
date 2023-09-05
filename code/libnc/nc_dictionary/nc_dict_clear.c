/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dict_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 23:18:57 by marvin            #+#    #+#             */
/*   Updated: 2023/05/14 23:18:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static void	helper(t_bstree *tree, void (*keydel)(void *), void (*valdel))
{
	if (!tree)
		return ;
	helper(tree->left, keydel, valdel);
	helper(tree->right, keydel, valdel);
	nc_pair_delete(tree->data, keydel, valdel);
	free(tree);
}

void	nc_dict_clear(t_dict *dict)
{
	if (!dict)
		return ;
	helper(dict->pairs, dict->keydel, dict->valdel);
}
