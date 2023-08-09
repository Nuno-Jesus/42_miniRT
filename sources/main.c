/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 17:58:07 by maricard         ###   ########.fr       */
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
	t_lightsource *l;
	
	l = nc_vector_at(r->sources, 0);
	if (keycode == ESC)
		quit(r);
	else if (keycode == W)
		l->origin.y += 5;
	else if (keycode == A)
		l->origin.x -= 5;
	else if (keycode == S)
		l->origin.y -= 5;
	else if (keycode == D)
		l->origin.x += 5;
	else if (keycode == C)
		l->origin.z -= 5;
	else if (keycode == V)
		l->origin.z += 5;
	render(r);
	return (keycode);
}

void	init_viewport(t_root *r)
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
	t_root	*root;

	if (argc != 2)
		message(NULL, "Usage: ./miniRT <scene>.rt");
	root = parse(argv[1]);
	init_viewport(root);
	init_graphics(root);
	root->disp.img = mlx_new_image(root->disp.mlx, WIDTH, HEIGHT);
	root->disp.addr = mlx_get_data_addr(root->disp.img, &root->disp.bpp, \
		&root->disp.line_length, &root->disp.endian);
	render(root);
	mlx_hook(root->disp.win, ON_KEYPRESS, KEYPRESS_MASK, on_keypress, root);
	mlx_hook(root->disp.win, ON_CLOSE, CLOSE_MASK, quit, root);
	//mlx_loop_hook(root->disp.mlx, render, root);
	mlx_loop(root->disp.mlx);
	destroy_root(&root);
	return (0);
}
