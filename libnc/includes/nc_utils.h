/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:52:16 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 19:59:02 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NC_UTILS_H
# define NC_UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <ctype.h>

/**
 * @brief Checks how many digits the number will have
 * 
 * @param n The number to check
 * @return int The size of the number
 */
int	nc_numlen(int n);

#endif