/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:01:11 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/07 15:39:58 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#ifdef __APPLE__
# include "../mlx_macos/mlx.h"

#else
# include "../mlx_linux/mlx.h"
# endif

# include "macros.h"
# include "get_next_line.h"
# include "libnc.h"
# include "vec3.h"
# include "structs.h"
# include "parser.h"
# include "utils.h"
# include "shapes.h"
# include "illumination.h"
# include "renderer.h"
# include "normal.h"

t_color	color_new(int r, int g, int b);

void	color_print(t_color *color);

#endif