/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:01:11 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/23 12:43:48 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifdef __APPLE__
#  include "../mlx_macos/mlx.h"
# else
#  include "../mlx_linux/mlx.h"
#  include <X11/X.h>
# endif

# include "macros.h"
# include "get_next_line.h"
# include "../libnc/includes/libnc.h"
# include "structs.h"
# include "vec3.h"
# include "color.h"
# include "debug.h"
# include "parser.h"
# include "utils.h"
# include "entities.h"
# include "renderer.h"

/**
 * @brief A callback to free the t_world struct memory and exit the program.
 * This function is called whenever the ESC key is clicked on or when the
 * X button is clicked on the window
 * 
 * @param world The t_world struct
 * @return int (not used)
 */
int		quit(t_world *world);

/**
 * @brief Updates the scene's camera position given the clicked key.
 * 
 * @param keycode The clicked key
 * @param w The world struct
 * @return int (dummy value)
 */
int		on_keypress(int keycode, t_world *w);

/**
 * @brief Initializes the mlx library pointer, window and image
 * 
 * @param w The t_world struct
 */
void	init_graphics(t_world *w);

void	search_shapes(t_world *w, t_vector *s);

void	change_ambient_light(t_world *w);

void	change_camera(t_world *w);

void	menu_execution(t_world *w);

void	write_shapes(t_world *w);

void	write_info1(t_world *w);

void	write_info2(t_world *w);

void	menu_text(t_world *w);

void	change_light(t_world *w);

int		menu_keys(int keycode, t_world *w);

void	render_menu(t_world *w);

void	light_info1(t_world *w);

void	light_info2(t_world *w);

void	light_info3(t_world *w);

int		light_menu(int keycode, t_world *w);

int		move_light(int keycode, t_world *w);

void	light(t_world *w, int id);

int		move_light2(int keycode, t_world *w, t_light *l);

int		move_light(int keycode, t_world *w);

void	main_menu(t_world *w);

#endif