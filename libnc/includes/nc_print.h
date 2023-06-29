/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:30:57 by marvin            #+#    #+#             */
/*   Updated: 2023/03/17 15:30:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_PRINT_H
# define NC_PRINT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

/**
 * @brief Outputs the character c to the file descriptor fd.
 * 
 * @param c The character to output
 * @param fd The file descriptor on which to write
 */
void	nc_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string s to the file descriptor fd.
 * 
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */
void	nc_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string s to the file descriptor fd, followed by 
 * a newline.
 * 
 * @param s The string to output
 * @param fd The file descriptor on which to write
 */
void	nc_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer n to the file descriptor fd.
 * 
 * @param n The integer to output
 * @param fd The file descriptor on which to write
 */
void	nc_putnbr_fd(int n, int fd);

#endif