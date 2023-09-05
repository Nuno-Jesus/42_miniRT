/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:27:42 by marvin            #+#    #+#             */
/*   Updated: 2023/03/17 15:27:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_MEMORY_H
# define NC_MEMORY_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with the 
 * constant byte c.
 * 
 * @param s The pointer to the area to fill 
 * @param c The character to place in the area
 * @param n The size of the area
 * @return void* The function returns its first argument
 */
void	*nc_memset(void *s, int c, size_t n);

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with the
 * constant byte 0.
 * 
 * @param s The pointer to the area to fill
 * @param n The size of the area
 */
void	nc_bzero(void *s, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 * areas must not overlap.
 * 
 * @param dest The pointer to the destination area
 * @param src The pointer to the source area
 * @param n The size of the area
 * @return void* The function returns its first argument
 */
void	*nc_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 * areas may overlap.
 * 
 * @param dest The pointer to the destination area
 * @param src The pointer to the source area
 * @param n The size of the area
 * @return void* The function returns its first argument
 */
void	*nc_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Searches in the memory area for the first occurrence of the character
 * c. Both c and the bytes of the memory area pointed to s are interpreted 
 * as unsigned char.
 * 
 * @param s The pointer to the area to search
 * @param c The character to search for
 * @param n The size of the area
 * @return void* The pointer to the matching byte or NULL if the character does
 */
void	*nc_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2.
 * 
 * @param s1 The pointer to the first area
 * @param s2 The pointer to the second area
 * @param n The size of the areas
 * @return int The function returns an integer less than, equal to, or greater
 * than zero if the first n bytes of s1 is found, respectively, to be less than,
 * to match, or be greater than the first n bytes of s2.
 */
int		nc_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each
 * and returns a pointer to the allocated memory. The memory is set to zero.
 * 
 * @param nmemb The number of elements
 * @param size The size of each element
 * @return void* The pointer to the allocated memory
 * @return NULL If the allocation fails
 */
void	*nc_calloc(size_t nmemb, size_t size);

#endif