/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:40:18 by marvin            #+#    #+#             */
/*   Updated: 2023/05/12 22:40:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_MATRIX_H
# define NC_MATRIX_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

/**
 * @brief Creates a new char matrix of given lines and columns. If columns is
 * 0, the function will return with only the pointers to the lines.
 * 
 * @param lines The number of lines.
 * @param columns The number of columns
 * @return void* A pointer to the new matrix.
 * @return NULL If the allocation fails.
 */
void	*nc_matrix_new(size_t lines, size_t columns);
/**
 * @brief Creates a duplicate of an existing matrix, using the copy function
 * to help on duplicating inner data.
 * 
 * @param matrix The matrix to copy.
 * @param copy The function containing the logic to copy the inner data.
 * @return void* The pointer to the new matrix.
 * @return NULL If the allocation fails.
 */
void	*nc_matrix_copy(void *matrix, void *(*copy)(void *));

/**
 * @brief Appends a new field of data to a new matrix, by creating a new one
 * with the result.
 * 
 * @note It does not free the memory of the original matrix
 * @param matrix The matrix to append the data to.
 * @param data The data to append.
 * @param copy The function containing the logic to copy the inner data.
 * @return void* A pointer to the new matrix with the appended data.
 */
void	*nc_matrix_append(void *matrix, void *data, void *(*copy)(void *));

/**
 * @brief Adds a new field of data to an existing matrix, by checking
 * what the last position is and adding the data to the next one.
 * 
 * @param matrix The matrix to add data to.
 * @param data The data to add.
 * @return void* The pointer to the matrix passed as argument.
 */
void	*nc_matrix_add(void *matrix, void *data);

/**
 * @brief Just like nc_matrix_append, but after using the old matrix
 * variable, it frees its memory.
 * 
 * @param matrix The matrix to add data to.
 * @param data The data to add.
 * @param del The delete function to delete the old matrix.
 * @return void* The pointer to the matrix passed as argument.
 */
void	*nc_matrix_join(void *matrix, void *data, void *(*copy)(void *), \
	void (*del)(void *));
/**
 * @brief Returns the size of a matrix.
 * 
 * @param matrix The matrix to get the size of.
 * @return size_t The size of the matrix.
 */
size_t	nc_matrix_size(void *matrix);

/**
 * @brief Frees all the memory associated with a matrix, using del as
 * a function to free the inner data.
 * 
 * @param matrix The matrix to free.
 * @param del The function containing the logic to free the inner data.
 */
void	nc_matrix_delete(void *matrix, void (*del)(void *));

/**
 * @brief Prints a matrix, using print as a function to print the inner data.
 * 
 * @param matrix The matrix to print.
 * @param print The function containing the logic to print the inner data.
 */
void	nc_matrix_print(void *matrix, void (*print)(void *, size_t));

/**
 * @brief Merges two matrices using the copy function to copy the inner 
 * positions.
 * 
 * @warning The two matrices must be of the same type!
 * @param m1 The first matrix
 * @param m2 The second matrix
 * @param copy The function to copy the elements of each matrix
 * @return A new allocated matrix with the elements of both
 * 
 */
void	**nc_matrix_merge(void **m1, void **m2, void *(*copy)(void *));

#endif