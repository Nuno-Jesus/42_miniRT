/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_bstree_traverse.c                                :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:56:21 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 17:56:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

static void	postorder(t_bstree **tree, void (*f)(void *))
{
	if (!(*tree))
		return ;
	if (*f)
		(*f)(*tree);
	postorder(&(*tree)->right, f);
	postorder(&(*tree)->left, f);
}

static void	preorder(t_bstree **tree, void (*f)(void *))
{
	if (!(*tree))
		return ;
	preorder(&(*tree)->right, f);
	preorder(&(*tree)->left, f);
	if (*f)
		(*f)(*tree);
}

static void	inorder(t_bstree **tree, void (*f)(void *))
{
	if (!(*tree))
		return ;
	inorder(&(*tree)->right, f);
	if (*f)
		(*f)(*tree);
	inorder(&(*tree)->left, f);
}

void	nc_bstree_traverse(t_bstree **tree, void (*f)(void *), \
	t_traversal type)
{
	if (!tree)
		return ;
	if (type == INORDER)
		inorder(tree, f);
	else if (type == PREORDER)
		preorder(tree, f);
	else if (type == POSTORDER)
		postorder(tree, f);
	else
		return ;
}
