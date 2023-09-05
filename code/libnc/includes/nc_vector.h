/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:52:13 by marvin            #+#    #+#             */
/*   Updated: 2023/05/17 19:52:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_VECTOR_H
# define NC_VECTOR_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

/**
 * @brief A struct that mimics the std::vector from C++
 * 
 * @param cmp The function to compare the elements of the vector
 * @param del The function to delete an element of the vector
 * @param cpy The function to copy an element of the vector
 * @param print The function to print an element of the vector
 * @param size The size of the vector
 * @param array The array of elements
 */
typedef struct s_vector
{
	uint32_t	size;
	int			(*cmp)(void *, void *);
	void		(*del)(void *);
	void		*(*cpy)(void *);
	void		(*print)(void *);
	void		**array;
}t_vector;

/**
 * @brief Create a new vector struct
 * 
 * @param cpy The function to copy the elements of the vector
 * @param cmp The function to compare the elements of the vector
 * @param del The function to delete the elements of the vector
 * @param print The function to print the elements of the vector
 * @return t_vector* The new vector struct
 * @return NULL If allocation fails
 */
t_vector	*nc_vector_new(void *(*cpy)(void *), int (*cmp)(void *, void *), \
	void (*del)(void *), void (*print)(void *));

/**
 * @brief Pushes a new element to the back of the vector
 * 
 * @param vector The vector to push to
 * @param element The element to push
 */
void		nc_vector_push(t_vector *vector, void *element);

/**
 * @brief Removes the last element of the vector
 * 
 * @param vector The vector to pop from
 */
void		nc_vector_pop(t_vector *vector);

/**
 * @brief Duplicates a vector instance with the elements of the original
 * vector
 * 
 * @param vector The vector to duplicate
 * @return t_vector* The new vector instance
 * @return NULL If allocation fails
 */
t_vector	*nc_vector_copy(t_vector *vector);

/**
 * @brief Searches for an element in the vector using the compare function
 * 
 * @param vector The vector to search on
 * @param element The element to search
 * @return void* The element if found
 * @return NULL If not found
 */
void		*nc_vector_find(t_vector *vector, void *element);

/**
 * @brief Removes all elements from the vector but not the vector itself
 * 
 * @param vector The vector to be cleared
 */
void		nc_vector_clear(t_vector *vector);

/**
 * @brief Clears the vector and frees the vector struct
 * 
 * @param vector The vector to delete
 */
void		nc_vector_delete(t_vector *vector);

/**
 * @brief Returns the element in the position i of the vector
 * 
 * @param vector The vector to get the element from
 * @param i The position of the element
 * @return void* The element
 * @return NULL If i is out of bounds
 */
void		*nc_vector_at(t_vector *vector, uint32_t i);

/**
 * @brief Merges two vectors into a new one with the elements of both vectors
 * 
 * @param v1 The first vector
 * @param v2 The second vector
 * @return t_vector* The final vector
 * @return NULL If allocation fails
 */
t_vector	*nc_vector_merge(t_vector *v1, t_vector *v2);

/**
 * @brief Prints the contents of the vector using the print function
 * 
 * @param vector The vector to sort
 */
void		nc_vector_print(t_vector *vector);

/**
 * @brief Returns the first element of the vector
 * 
 * @param vector The vector to get the element from
 * @return void* The first element
 * @return NULL If the vector is empty
 */
void		*nc_vector_first(t_vector *vector);

/**
 * @brief Returns the last element of the vector
 * 
 * @param vector The vector to get the element from
 * @return void* The last element
 * @return NULL If the vector is empty
 */
void		*nc_vector_last(t_vector *vector);

#endif