/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_matrix_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:44:59 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/03 16:13:12 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	*nc_matrix_join(void *matrix, void *data, void *(*copy)(void *), \
	void (*del)(void *))
{
	void	*appended;

	appended = nc_matrix_append(matrix, data, copy);
	nc_matrix_delete(matrix, del);
	return (appended);
}
