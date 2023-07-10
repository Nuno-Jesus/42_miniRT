/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:24:35 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/10 18:28:41 by ncarvalh         ###   ########.fr       */
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
	nc_vector_delete((*root)->sources);
	nc_matrix_delete((*root)->map, &free);
	if ((*root)->disp.img)
		mlx_destroy_image((*root)->disp.mlx, (*root)->disp.img);
	if ((*root)->disp.win)
		mlx_destroy_window((*root)->disp.mlx, (*root)->disp.win);
	if ((*root)->disp.mlx)
		mlx_destroy_display((*root)->disp.mlx);
	nc_free((*root)->disp.mlx);
	free(*root);
	*root = NULL;
}
