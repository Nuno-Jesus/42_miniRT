/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/07 19:35:17 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_graphics(t_root *r)
{
	r->disp.mlx = mlx_init();
	if (!r->disp.mlx)
		message(r, "Failed allocation on mlx pointer\n");
	r->disp.win = mlx_new_window(r->disp.mlx, WIDTH, HEIGHT, "miniRT");
	if (!r->disp.win)
		message(r, "Failed allocation on window pointer\n");
}

int	quit(t_root *root)
{
	destroy_root(&root);
	exit(EXIT_SUCCESS);
}

int	on_keypress(int keycode, t_root *r)
{
	(void)r;
	if (keycode == ESC)
		quit(r);
	printf("Pressed key %d\n", keycode);
	return (keycode);
}

int	render_frame(t_root *r)
{	
	(void)r;
	return (0);
}

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * WIDTH + x) * (data->bits_per_pixel / 8);
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int x = 0; x < WIDTH; x += 1)
		for (int y = 0; y < HEIGHT; y += 1)
			my_mlx_pixel_put(&img, x, y, (sin(RADIANS(x)) + cos(RADIANS(y))) * 255);
			
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
