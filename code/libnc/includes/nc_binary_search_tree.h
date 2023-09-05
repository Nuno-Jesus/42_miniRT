/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_bstree.h                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:46:58 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 16:46:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_BINARY_SEARCH_TREE_H
# define NC_BINARY_SEARCH_TREE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

# include "nc_linked_list.h"

typedef enum e_traversal
{
	PREORDER,
	INORDER,
	POSTORDER
}t_traversal;

/**
 * @brief A binary search tree node
 * 
 * @param data The content of the node
 * @param depth The depth of the node
 * @param left The left child of the node
 * @param right The right child of the node
 */
typedef struct s_bstree
{
	void			*data;
	uint32_t		depth;
	struct s_bstree	*left;
	struct s_bstree	*right;
}t_bstree;

/**
 * @brief Creates a new binary search tree node
 * 
 * @param content The nodes content
 * @param depth The depth the node will have
 * @return t_bstree* The new node
 * @return NULL If the allocation fails
 */
t_bstree	*nc_bstree_new(void *content, uint32_t depth);

/**
 * @brief Duplicates a node of a binary search tree and its content
 * 
 * @param node The node to duplicate
 * @param copy The function used to copy the content
 * @return t_bstree* The new node
 * @return NULL If the allocation fails
 */
t_bstree	*nc_bstree_copy(t_bstree *node, void *(*copy)(void *));

/**
 * @brief Duplicates all the nodes of a binary search tree
 * 
 * @param tree The tree to duplicate
 * @param copy The function used to copy the content of each node
 * @return t_bstree* The new tree
 * @return NULL If the allocation fails
 */
t_bstree	*nc_bstree_deepcopy(t_bstree *tree, void *(*copy)(void *));

/**
 * @brief Inserts a new node in a binary search tree
 * 
 * @param tree The tree to insert the node in
 * @param data The content of the new node
 * @param cmp The function used to compare the content of the nodes
 * @param depth The depth the new node will have
 * @return t_bstree* The new tree
 * @return NULL If the allocation fails
 */
t_bstree	*nc_bstree_insert(t_bstree *tree, void *data, \
	int (*cmp)(void *, void *), uint32_t depth);

/**
 * @brief Checks if a node exists in a tree using the data and the cmp
 * function to perform the comparison
 * 
 * @param tree The tree to search on
 * @param data The data to use as a reference
 * @param cmp The comparison function
 * @return t_bstree* The node if it exists
 * @return NULL If the node doesn't exist
 */
t_bstree	*nc_bstree_find(t_bstree *tree, void *data, \
	int (*cmp)(void *, void *));

/**
 * @brief Deletes a node from a binary search tree
 * 
 * @note This function does not disconnect the node from the tree.
 * Instead, the user should take care of that before calling this function
 * to prevent memory leaks.
 * @param node The node to delete
 * @param del The function used to delete the content of the node
 */
void		nc_bstree_delete(t_bstree *node, void (*del)(void *));

/**
 * @brief Deletes all the nodes of a binary search tree
 * 
 * @param tree The tree to delete
 * @param del The function used to delete the content of each node
 */
void		nc_bstree_clear(t_bstree *tree, void (*del)(void *));

/**
 * @brief Prints a binary search tree using postorder traversal
 * 
 * @param tree The tree to print
 * @param print The function used to print the content of each node
 */
void		nc_bstree_print(t_bstree *tree, void (*print)(void *));

/**
 * @brief Traverses a binary search tree using the specified traversal
 * and applies a function to each node. The traversal can be one of the 
 * following three:
 * 	- PREORDER
 * 	- INORDER
 * 	- POSTORDER
 * 
 * @param tree The tree to traverse
 * @param f The function to apply to each node
 * @param type The type of traversal to use
 */
void		nc_bstree_traverse(t_bstree **tree, void (*f)(), t_traversal type);

/**
 * @brief Counts the number of nodes in a binary search tree
 * 
 * @param tree The tree to count
 * @return uint32_t The number of nodes
 */
uint32_t	nc_bstree_count(t_bstree *tree);

/**
 * @brief Iterates over the binary search tree and returns the maximum
 * depth of the tree
 * 
 * @param tree The tree to search on
 * @return uint32_t The maximum depth of the tree
 */
uint32_t	nc_bstree_height(t_bstree *tree);

/**
 * @brief Flattens the binary search tree into a linked list. The left nodes
 * are placed before the right nodes, which means that the list will be sorted.
 * 
 * @param tree The tree to flatten
 * @return t_list* The new sorted list
 * @return NULL If the allocation fails
 */
t_list		*nc_bstree_to_list(t_bstree *tree, void *(*copy)(void *));

#endif