/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:24:35 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/24 15:39:13 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	destroy_root(t_root **root)
{
	if (!(*root))
		return ;
	nc_vector_delete((*root)->shapes);
	nc_vector_delete((*root)->sources);
	nc_matrix_delete((*root)->map, &free);
	if ((*root)->disp.img)
		mlx_destroy_image((*root)->disp.mlx, (*root)->disp.img);
	if ((*root)->disp.win)
		mlx_destroy_window((*root)->disp.mlx, (*root)->disp.win);
	//if ((*root)->disp.mlx)
	//	mlx_destroy_display((*root)->disp.mlx);
	nc_free((*root)->disp.mlx);
	free(*root);
	*root = NULL;
}
