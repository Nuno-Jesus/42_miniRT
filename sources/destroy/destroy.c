/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:24:35 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/03 17:16:43 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	destroy_root(t_root **root)
{
	if (!(*root))
		return ;
	nc_vector_delete((*root)->planes);
	nc_vector_delete((*root)->spheres);
	nc_vector_delete((*root)->cylinders);
	free(*root);
	*root = NULL;
}