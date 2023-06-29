/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:50:44 by crypto            #+#    #+#             */
/*   Updated: 2023/06/29 20:05:10 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNC_H
# define LIBNC_H

//! Standard libraries and some more
# include "../libnc/includes/nc_is.h"
# include "../libnc/includes/nc_str.h"
# include "../libnc/includes/nc_print.h"
# include "../libnc/includes/nc_memory.h"
# include "../libnc/includes/nc_conversions.h"

//! Data structures
# include "../libnc/includes/nc_pair.h"
# include "../libnc/includes/nc_matrix.h"
# include "../libnc/includes/nc_vector.h"
# include "../libnc/includes/nc_binary_search_tree.h"
# include "../libnc/includes/nc_dictionary.h"
# include "../libnc/includes/nc_linked_list.h"
# include "../libnc/includes/nc_utils.h"

//! Useful macros

// Returns the maximum between a and b
# define MAX(a, b) ((a) > (b) ? (a) : (b))
// Returns the minimum between a and b
# define MIN(a, b) ((a) < (b) ? (a) : (b))
// Returns the absolute value of x
# define ABS(x) ((x) < 0 ? -(x) : (x))

// Returns 1 if x is odd, 0 otherwise
# define ODD(x) ((x) & 1)
// Returns 1 if x is even, 0 otherwise
# define EVEN(x) !ODD(x)

// Return the value of the nth bit of x
# define BIT(n) (1 << (n))

#endif
