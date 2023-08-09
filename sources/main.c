/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 20:09:27 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_graphics(t_world *r)
{
	r->disp.mlx = mlx_init();
	if (!r->disp.mlx)
		message(r, "Failed allocation on mlx pointer\n");
	r->disp.win = mlx_new_window(r->disp.mlx, WIDTH, HEIGHT, "miniRT");
	if (!r->disp.win)
		message(r, "Failed allocation on window pointer\n");
}

int	quit(t_world *world)
{
	destroy_world(&world);
	exit(EXIT_SUCCESS);
}

int	on_keypress(int keycode, t_world *r)
{
	t_light *l;
	
	l = nc_vector_at(r->lights, 0);
	if (keycode == ESC)
		quit(r);
	else if (keycode == W)
		l->center.y += 5;
	else if (keycode == A)
		l->center.x -= 5;
	else if (keycode == S)
		l->center.y -= 5;
	else if (keycode == D)
		l->center.x += 5;
	else if (keycode == C)
		l->center.z -= 5;
	else if (keycode == V)
		l->center.z += 5;
	render(r);
	return (keycode);
}

void	init_viewport(t_world *r)
{
	double	ratio;

	ratio = RATIO;
	r->wview = tan(RADIANS(r->camera.fov / 2));
	r->hview = r->wview / ratio;
	r->right = vec3_normalize(vec3_cross(r->camera.normal, UPGUIDE));
	r->up = vec3_normalize(vec3_cross(r->camera.normal, r->right));
	r->right = vec3_normalize(vec3_cross(r->camera.normal, r->up));
	vec3_print(vec3_cross(r->camera.normal, UPGUIDE));
	vec3_print(r->camera.normal);
	printf("Right ");
	vec3_print(r->right);
	printf("Up ");
	vec3_print(r->up);
	printf("wview: %f\n", r->wview);
	printf("hview: %f\n", r->hview);
	printf("------------------------------\n");
}

int	main(int argc, char **argv)
{
	t_world	*world;

	if (argc != 2)
		message(NULL, "Usage: ./miniRT <scene>.rt");
	world = parse(argv[1]);
	init_viewport(world);
	init_graphics(world);
	world->disp.img = mlx_new_image(world->disp.mlx, WIDTH, HEIGHT);
	world->disp.addr = mlx_get_data_addr(world->disp.img, &world->disp.bpp, \
		&world->disp.line_length, &world->disp.endian);
	render(world);
	mlx_hook(world->disp.win, ON_KEYPRESS, KEYPRESS_MASK, on_keypress, world);
	mlx_hook(world->disp.win, ON_CLOSE, CLOSE_MASK, quit, world);
	//mlx_loop_hook(world->disp.mlx, render, world);
	mlx_loop(world->disp.mlx);
	destroy_world(&world);
	return (0);
}
