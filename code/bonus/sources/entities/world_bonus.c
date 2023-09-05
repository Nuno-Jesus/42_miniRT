/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:32:20 by crypto            #+#    #+#             */
/*   Updated: 2023/09/04 13:18:39 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_world	*world_new(void)
{
	t_world	*world;

	world = nc_calloc(1, sizeof(t_world));
	if (!world)
		return (NULL);
	world->shapes = nc_vector_new((void *)&shape_copy, NULL, \
		&free, (void *)&shape_print);
	world->lights = nc_vector_new((void *)&light_copy, NULL, \
		&free, (void *)&light_print);
	return (world);
}

void	destroy_world(t_world **world)
{
	if (!(*world))
		return ;
	nc_vector_delete((*world)->shapes);
	nc_vector_delete((*world)->lights);
	nc_matrix_delete((*world)->map, &free);
	if ((*world)->disp.img)
		mlx_destroy_image((*world)->disp.mlx, (*world)->disp.img);
	if ((*world)->disp.menu)
		mlx_destroy_image((*world)->disp.mlx, (*world)->disp.menu);
	if ((*world)->disp.win)
		mlx_destroy_window((*world)->disp.mlx, (*world)->disp.win);
	if ((*world)->disp.mlx)
		mlx_destroy_display((*world)->disp.mlx);
	nc_free((*world)->disp.mlx);
	free(*world);
	*world = NULL;
}
