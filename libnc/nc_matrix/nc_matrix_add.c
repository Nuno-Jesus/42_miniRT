/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:45:04 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 19:48:55 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_matrix_add(void *matrix, void *data)
{
	size_t	len;

	len = nc_matrix_size(matrix);
	((char **)matrix)[len] = data;
	return (matrix);
}
