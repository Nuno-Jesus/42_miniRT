/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:29:43 by crypto            #+#    #+#             */
/*   Updated: 2023/08/16 16:24:58 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// void	put_image_pixel(t_img *img, t_color c, int x, int y)
// {
// 	char	*dst;

// 	//Print img->addr
// 	printf("img->addr = %p\n", img->addr);
// 	dst = img->addr + (y * WIDTH + x) * (img->bpp / 8);
// 	//Print x and y
// 	// printf("img= %p\n", img);
// 	printf("x = %d\n", x);
// 	printf("y = %d\n", y);
// 	*(unsigned int *)dst = (c.t << 24 | c.r << 16 | c.g << 8 | c.b);

// }

void	*test(t_runner *worker)
{
	t_vec3	coords;
	t_vec3	factors;
	t_ray	ray;
	t_hit	closest;
	t_world	*w;
	
	w = worker->world;
	coords.y = worker->min_y - 1;
	while (++coords.y < worker->max_y)
	{
		coords.x = -1;
		while (++coords.x < worker->image.width)
		{
			closest.color = BLACK;
			closest.shape = NULL;
			closest.t = INFINITY;
			factors = pixels_to_viewport(coords.x, coords.y);
			ray = make_ray(w, factors);
			if (world_hit(w->shapes, &ray, &closest))
				illuminate(w, &closest);
			// pthread_mutex_lock(&w->mtx);
			// put_image_pixel(&worker->world->disp., closest.color, coords.x, coords.y);
			// pthread_mutex_unlock(&w->mtx);
			put_pixel(w, closest.color, coords.x, coords.y);
		}
	}
	return (NULL);
}

void	prepare_threads(t_world	*world, t_runner threads[NUM_THREADS])
{
	uint8_t		i;

	i = -1;
	while (++i < NUM_THREADS)	
	{
		threads[i].image.height = HEIGHT/NUM_THREADS;
		threads[i].image.width = WIDTH;
		threads[i].image.addr = world->disp.addr + (i * threads[i].image.height * WIDTH * (world->disp.bpp / 8));
		threads[i].min_y = i * threads[i].image.height;
		threads[i].max_y = (i + 1) * threads[i].image.height;
		threads[i].world = world;

		//Debug all the fields of the threads[i]
		// printf("threads[%d].image.height = %d\n", i, threads[i].image.height);
		// printf("threads[%d].image.width = %d\n", i, threads[i].image.width);
		// printf("threads[%d].min_y = %d\n", i, threads[i].min_y);
		// printf("threads[%d].max_y = %d\n", i, threads[i].max_y);
		// printf("\n");
	}	
}

void	launch_threads(t_world *world)
{
	uint8_t		i;
	t_runner	threads[NUM_THREADS];

	// nc_bzero(world->disp.addr, WIDTH * HEIGHT * (world->disp.bpp / 8));
	prepare_threads(world, threads);
	i = -1;
	while (++i < NUM_THREADS)
		pthread_create(&threads[i].thread, NULL, (void *)test, &threads[i]);
	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(threads[i].thread, NULL);	
	mlx_put_image_to_window(world->disp.mlx, world->disp.win, world->disp.img,0, 0);
}