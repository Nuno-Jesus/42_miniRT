/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:29:43 by crypto            #+#    #+#             */
/*   Updated: 2023/08/18 19:02:58 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//!
void	allocate_thread_screen(t_world *world, t_runner threads[NUM_THREADS])
{
	uint8_t	i;

	i = -1;
	while (++i < NUM_THREADS)
	{
		threads[i].min_y = i * (HEIGHT / NUM_THREADS);
		threads[i].max_y = (i + 1) * (HEIGHT / NUM_THREADS);
		threads[i].world = world;
	}
}

void	multithread(t_world *world)
{
	uint8_t		i;
	t_runner	threads[NUM_THREADS];

	allocate_thread_screen(world, threads);
	i = -1;
	while (++i < NUM_THREADS)
		pthread_create(&threads[i].thread, NULL, (void *)render, &threads[i]);
	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(threads[i].thread, NULL);
	mlx_put_image_to_window(world->disp.mlx, world->disp.win, \
		world->disp.img, 0, 0);
}
