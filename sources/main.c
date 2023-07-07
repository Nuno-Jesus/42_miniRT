/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/07 23:20:49 by ncarvalh         ###   ########.fr       */
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
	if (keycode == ESC)
		quit(r);
	printf("Pressed key %d\n", keycode);
	return (keycode);
}

void	init_viewport(t_root *r)
{
	float	ratio;

	ratio = RATIO;
	r->wview = tan(RADIANS(r->camera.fov));
	r->hview = r->wview / ratio;
	r->right = vec3_normalize(vec3_cross(r->camera.normal, UPGUIDE));
	vec3_print(r->right);
	r->up = vec3_normalize(vec3_cross(r->camera.normal, r->right));
	vec3_print(r->up);
	r->right = vec3_normalize(vec3_cross(r->camera.normal, r->up));
	vec3_print(r->right);
}

int	main(int argc, char **argv)
{
	t_root	*root;

	if (argc != 2)
		message(NULL, "Usage: ./miniRT <scene>.rt");
	root = parse(argv[1]);
	init_viewport(root);
	init_graphics(root);
	render(root);
	// mlx_hook(root->disp.win, ON_KEYPRESS, KEYPRESS_MASK, on_keypress, root);
	// mlx_hook(root->disp.win, ON_CLOSE, CLOSE_MASK, quit, root);
	// mlx_loop_hook(root->disp.mlx, render, root);
	// mlx_loop(root->disp.mlx);
	destroy_root(&root);
	return (0);
}
