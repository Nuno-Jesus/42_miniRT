/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/29 16:03:13 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_graphics(t_world *w)
{
	w->disp.mlx = mlx_init();
	if (!w->disp.mlx)
		message(w, ERROR_MALLOC("init_graphics (mlx)"));
	w->disp.win = mlx_new_window(w->disp.mlx, WIDTH, HEIGHT, "miniRT");
	if (!w->disp.win)
		message(w, ERROR_MALLOC("init_graphics (mlx window)"));
	w->disp.img = mlx_new_image(w->disp.mlx, WIDTH, HEIGHT);
	if (!w->disp.img)
		message(w, ERROR_MALLOC("init_graphics (mlx image)"));
	w->disp.addr = mlx_get_data_addr(w->disp.img, &w->disp.bpp, \
		&w->disp.line_length, &w->disp.endian);
	if (!w->disp.addr)
		message(w, ERROR_MALLOC("init_graphics (mlx image address)"));
	w->disp.menu = mlx_new_image(w->disp.mlx, WIDTH/6, HEIGHT);
	if (!w->disp.img)
		message(w, ERROR_MALLOC("init_graphics (mlx menu image)"));
	
}

int	quit(t_world *world)
{
	destroy_world(&world);
	exit(EXIT_SUCCESS);
}

int	on_keypress(int keycode, t_world *w)
{
	t_menu_state (*handlers[])() = 
	{
		(void *)handle_closed_menu,
		(void *)handle_opened_menu,
		(void *)handle_camera_changes,
		(void *)handle_amb_light_changes,
		// handle_light_choice,
		// handle_light_changes,
		// handle_sphere_choice,
		// handle_sphere_changes,
		// handle_plane_choice,
		// handle_plane_changes,
		// handle_cylinder_choice,
		// handle_cylinder_changes,		
		// handle_cone_choice,
		// handle_cone_changes,		
	};
	if (keycode == ESC)
		quit(w);
	w->state = handlers[w->state](keycode, w);
	return (keycode);
}

int	main(int argc, char **argv)
{
	t_world		*world;

	if (argc != 2)
		message(NULL, ERROR_USAGE);
	world = parse(argv[1]);
	init_viewport(world);
	init_graphics(world);
	multithread(world);
	mlx_hook(world->disp.win, KeyPress, KeyPressMask, on_keypress, world);
	mlx_hook(world->disp.win, DestroyNotify, StructureNotifyMask, quit, world);
	mlx_loop(world->disp.mlx);
	destroy_world(&world);
	return (0);
}
