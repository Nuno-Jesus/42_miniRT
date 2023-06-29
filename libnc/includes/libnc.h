/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:50:44 by crypto            #+#    #+#             */
/*   Updated: 2023/05/18 15:27:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNC_H
# define LIBNC_H

//! Standard libraries and some more
# include "nc_is.h"
# include "nc_str.h"
# include "nc_print.h"
# include "nc_memory.h"
# include "nc_conversions.h"

//! Data structures
# include "nc_pair.h"
# include "nc_matrix.h"
# include "nc_vector.h"
# include "nc_binary_search_tree.h"
# include "nc_dictionary.h"
# include "nc_linked_list.h"

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
