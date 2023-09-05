/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:29:33 by marvin            #+#    #+#             */
/*   Updated: 2023/03/17 15:29:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_IS_H
# define NC_IS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

/**
 * @brief Checks if a character is alphabetic
 * 
 * @param c The character to check
 * @return int 1 if the character is alphabetic, 0 otherwise
 */
int		nc_isalpha(int c);

/**
 * @brief Checks if a character is a digit
 * 
 * @param c The character to check
 * @return int 1 if the character is a digit, 0 otherwise
 */
int		nc_isdigit(int c);

/**
 * @brief Checks if a character is alphanumeric
 * 
 * @param c The character to check
 * @return int 1 if the character is alphanumeric, 0 otherwise
 */
int		nc_isalnum(int c);

/**
 * @brief Checks if a character is on the ASCII table
 * 
 * @param c The character to check
 * @return int 1 if the character is on the ASCII, 0 otherwise
 */
int		nc_isascii(int c);

/**
 * @brief Checks if a character is printable
 * 
 * @param c The character to check
 * @return int 1 if the character is printable, 0 otherwise
 */
int		nc_isprint(int c);

/**
 * @brief Checks if a given string represents a number, until
 * one of the characters reaches a delimiter
 * 
 * @param str The string to parse
 * @param delims The set of delimeters used to stop
 * @return true If the string represents a number
 * @return false Otherwise
 */
bool	nc_isnum(char *str, char *delims);

#endif