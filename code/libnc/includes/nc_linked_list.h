/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:28:47 by marvin            #+#    #+#             */
/*   Updated: 2023/03/17 15:28:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_LINKED_LIST_H
# define NC_LINKED_LIST_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

/**
 * @brief A linked list node.
 * 
 * @param content The content of the node
 * @param next The next node in the list
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Creates a new list node with the given content.
 * 
 * @param content The content of the node
 * @return t_list* The new node
 * @return NULL If the allocation fails
 */
t_list	*nc_list_new(void *content);

/**
 * @brief Adds a new node to the front of the list.
 * 
 * @param list A pointer to the first node of the list
 * @param new The new node to add
 */
void	nc_list_add_front(t_list **list, t_list *new);

/**
 * @brief Counts the number of nodes in the list.
 * 
 * @param list The first node of the list
 * @return int The number of nodes in the list
 */
int		nc_list_size(t_list *list);

/**
 * @brief Returns the last node of the list.
 * 
 * @param list The last node of the list
 * @return t_list* The last node of the list
 * @return NULL If the list is empty
 */
t_list	*nc_list_last(t_list *list);

/**
 * @brief Adds a new node to the end of the list.
 * 
 * @param list A pointer to the first node of the list
 * @param new The new node to add
 */
void	nc_list_add_back(t_list **list, t_list *new);

/**
 * @brief Deletes a list node
 * 
 * @warning This function does not disconnect the node from the list.
 * If this function is invoked with the first node of the list, the list
 * will be lost in memory.
 * @param list A pointer to the first node of the list
 */
void	nc_list_delone(t_list *list, void (*del)(void*));

/**
 * @brief Deletes all the nodes of the list.
 * 
 * @param list A pointer to the first node of the list
 */
void	nc_list_clear(t_list **list, void (*del)(void*));

/**
 * @brief Iterates over the list and applies the given function pointer
 * to each node.
 * 
 * @param list A pointer to the first node of the list
 * @param f The function pointer to apply to each node
 */
void	nc_list_iter(t_list *list, void (*f)(void *));

/**
 * @brief Maps the argument list into a new one, by using the function pointer
 * passed as parameter to transform the original nodes contents. The function 
 * pointer receives the node's content as a parameter.
 * 
 * @param list A pointer to the first node of the list
 * @param f The function pointer to apply to each node
 * @param del The function pointer to delete the node's content
 * @return t_list* The new list
 * @return NULL If the allocation fails
 */
t_list	*nc_list_map(t_list *list, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Returns the node at the given index.
 * 
 * @param begin_list The first node of the list
 * @param nbr The index of the node to return
 * @return t_list* The node at the given index
 * @return NULL If the index is out of range
 */
t_list	*nc_list_at(t_list *begin_list, unsigned int nbr);

/**
 * @brief Reverses the order of the nodes in the list.
 * 
 * @param begin_list A pointer to the first node of the list
 */
void	nc_list_reverse(t_list **begin_list);

/**
 * @brief Given a list to search on and a reference data to compare with,
 * returns the node of the list that matches the reference data. The 
 * comparison is achieved by using the given function pointer.
 * 
 * @param begin_list The first node of the list
 * @param data_ref The reference data to compare with
 * @param cmp The function pointer to use for the comparison
 * @return t_list* The node that matches the reference data
 * @return NULL If no node matches the reference data
 */
t_list	*nc_list_find(t_list *begin_list, void *data_ref, \
	int (*cmp)(void *, void *));

// char **nc_list_to_matrix(t_list *list);
#endif