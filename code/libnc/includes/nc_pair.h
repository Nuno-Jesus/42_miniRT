/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dictionary.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:16:42 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 14:16:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_PAIR_H
# define NC_PAIR_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

/**
 * @brief A struct that holds a key and a value
 * 
 * @param key The key of the pair
 * @param value The value of the pair
 */
typedef struct s_pair
{
	void	*key;
	void	*value;
}t_pair;

/**
 * @brief Creates a new pair pointer with the given key and value
 * 
 * @param key The key to assign
 * @param value The value to assign
 * @return t_pair* A point to the new pair struct
 * @return NULL If allocation fails
 */
t_pair	*nc_pair_new(void *key, void *value);

/**
 * @brief Duplicates the given pair into a newly allocated pair. If the 
 * keycpy and valcpy functions are provided, they will be used to duplicate 
 * the key and value respectively. If they are NULL, the key and value will
 * be assigned directly to the new pair.
 * 
 * @param pair The pair to copy
 * @param keycpy The function to copy the key
 * @param valcpy The function to copy the value
 * @return t_pair* A pointer to the new pair struct
 * @return NULL If allocation fails
 */
t_pair	*nc_pair_copy(t_pair *pair, void *(*keycpy)(), void *(*valcpy)());

/**
 * @brief Swaps the key and value of the given pair into a newly allocated 
 * pair. It uses the keycpy and valcpy functions to duplicate the key and
 * value respectively. 
 * 
 * @note If the keycpy and valcpy functions are NULL, the key and value will
 * be assigned directly to the new pair.
 * @param pair The pair to swap
 * @param keycpy The function to copy the key
 * @param valcpy The function to copy the value
 * @return t_pair* A pointer to the new pair struct
 * @return NULL If allocation fails
 */
t_pair	*nc_pair_swap(t_pair *pair, void *(*keycpy)(), void *(*valcpy)());

/**
 * @brief Converts the given pair into a string using the provided keystr and
 * valistr functions.
 * 
 * @param pair The pair to convert
 * @param keystr The function to convert the key to a string
 * @param valistr The function to convert the value to a string
 * @return char* A pointer to the new string
 * @return NULL If allocation fails
 */
char	*nc_pair_tostring(t_pair *pair, char *(*keystr)(), char *(*valstr)());

/**
 * @brief Frees the given pair using the provided keydel and valdel functions.
 * @note If the keydel and valdel functions are NULL, the key and value will
 * be freed (treated as primitive types that cannot be freed).  
 
 * @param pair The pair to free 
 * @param keydel The function to delete the key
 * @param valdel The function to delete the value
 */
void	nc_pair_delete(t_pair *pair, void (*keydel)(), void (*valdel)());

/**
 * @brief Clears the key and values of a pair, without freeing the pair itself
 * 
 * @param pair The pair to clear
 * @param keydel The function to delete the key
 * @param valdel The function to delete the value
 */
void	nc_pair_clear(t_pair *pair, void (*keydel)(), void (*valdel)());

/**
 * @brief Prints the given pair using the provided keystr and valistr functions.
 * 
 * @param pair The pair to print
 * @param keystr The function to convert the key to a string
 * @param valistr The function to convert the value to a string
 */
void	nc_pair_print(t_pair *pair, char *(*keystr)(), char *(*valstr)());

#endif 