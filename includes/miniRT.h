/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:01:11 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/07 23:06:13 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// # ifdef OS_LINUX
# include "../mlx_linux/mlx.h"
// # else
// #  include "../mlx_macos/mlx.h"
// # endif

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

t_color	color_new(int r, int g, int b);

#endif