/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_bstree_print.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:23:49 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 18:23:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static void	display(t_bstree *node, void (*print)(void *))
{
	uint32_t	i;

	i = -1;
	while (++i < node->depth)
		nc_putstr_fd("│   ", STDOUT_FILENO);
	if (node->left)
		nc_putstr_fd("├── ", STDOUT_FILENO);
	else
		nc_putstr_fd("└── ", STDOUT_FILENO);
	print(node->data);
}

static void	helper(t_bstree *tree, void (*print)(void *), uint32_t depth)
{
	if (!tree)
		return ;
	tree->depth = depth;
	display(tree, print);
	helper(tree->right, print, depth + 1);
	helper(tree->left, print, depth + 1);
}

void	nc_bstree_print(t_bstree *tree, void (*print)(void *))
{
	if (!tree || !print)
		return ;
	helper(tree, print, 0);
}
