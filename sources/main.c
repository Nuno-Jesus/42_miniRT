/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/06 17:05:08 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// t_root	*root;

	// if (argc != 2)
	// 	message(NULL, "Usage: ./miniRT <scene>.rt");
	// root = parse(argv[1]);
	// destroy_root(&root);
	// return (0);

	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
