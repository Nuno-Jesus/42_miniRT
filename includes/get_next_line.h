/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:01:24 by marvin            #+#    #+#             */
/*   Updated: 2022/11/12 11:01:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/**
 * @brief Opens the file descriptor fd and retrieves the next available
 * line. A line is described as all the characters until the next
 * '\n' is found or until the file ends.
 * 
 * @param fd The file descriptor to read from
 * @return char* The next line if available
 * @return NULL If EOF was reached, or if the fd is invalid
 */
char	*get_next_line(int fd);

/**
 * @brief Gets the string size until a delimiter c is found or until
 * the end of the string is reached.
 * 
 * @param s The string to count the size from
 * @param c The delimiter to be considered
 * @return The final length
 */
size_t	ft_strclen(const char *s, int c);

/**
 * @brief Finds a character in a string.
 * 
 * @param s The string to search on
 * @param c The character to search for
 * @return char* The address where the character was found
 * @return NULL If the character wasn't found or if s was NULL
 */
char	*ft_strchr_mod(const char *s, int c);

/**
 * @brief Duplicates the first n characters of the string s
 * 
 * @param s The address of the first character
 * @param n The number of characters to duplicate
 * @return char* A new allocated pointer with the duplicated string
 * @return NULL On error
 */
char	*ft_strndup(const char *s, size_t n);

/**
 * @brief Concatenates 2 strings, returning a pointer to the new string
 * If one of the strings is NULL, only one will be used and the concatenation
 * will be done with a NULL byte ('\0').
 * 
 * @param s1 The first string
 * @param s2 The second string
 * @return char* A new allocated pointer to the result
 */
char	*ft_strjoin_mod(char *s1, const char *s2);

#endif