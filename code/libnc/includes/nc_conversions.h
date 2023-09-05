/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:30:29 by marvin            #+#    #+#             */
/*   Updated: 2023/03/17 15:30:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_CONVERSIONS_H
# define NC_CONVERSIONS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

/**
 * @brief Converts a string to an integer
 * 
 * @param nptr The pointer of the string to convert
 * @return int The integer converted from the string
 */
int		nc_atoi(const char *nptr);

/**
 * @brief Converts a string to a double
 * 
 * @param str The string to convert
 * @return double The double converted from the string
 */
double	nc_atod(char *str);

/**
 * @brief Converts a lowecase character to an uppercase character
 * 
 * @param c The character to convert
 * @return int The converted character
 */
int		nc_toupper(int c);

/**
 * @brief Converts an uppercase character to a lowercase character
 * 
 * @param c The character to convert
 * @return int The converted character
 */
int		nc_tolower(int c);

/**
 * @brief Converts a character to an integer
 * 
 * @param c The character to convert
 * @return int The converted character
 */
int		nc_tonum(int c);

/**
 * @brief Converts an integer to a character
 * 
 * @param c The integer to convert
 * @return int The converted integer
 */
int		nc_tochar(int c);

/**
 * @brief Converts an integer to a string
 * 
 * @param n The integer to convert
 * @return char* The converted integer
 */
char	*nc_itoa(int n);

#endif