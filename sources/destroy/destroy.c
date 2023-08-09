/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:24:35 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 20:09:27 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	destroy_world(t_world **world)
{
	if (!(*world))
		return ;
	nc_vector_delete((*world)->shapes);
	nc_vector_delete((*world)->lights);
	nc_matrix_delete((*world)->map, &free);
	if ((*world)->disp.img)
		mlx_destroy_image((*world)->disp.mlx, (*world)->disp.img);
	if ((*world)->disp.win)
		mlx_destroy_window((*world)->disp.mlx, (*world)->disp.win);
	#ifndef __APPLE__
	if ((*world)->disp.mlx)
		mlx_destroy_display((*world)->disp.mlx);
	#endif
	nc_free((*world)->disp.mlx);
	free(*world);
	*world = NULL;
}
