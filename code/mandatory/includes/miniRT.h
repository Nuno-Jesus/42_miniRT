/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:01:11 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/04 16:50:40 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifdef __APPLE__
#  include "../../mlx_macos/mlx.h"
# else
#  include "../../mlx_linux/mlx.h"
#  include <X11/X.h>
# endif

# include "macros.h"
# include "../../gnl/get_next_line.h"
# include "../../libnc/includes/libnc.h"
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

#endif