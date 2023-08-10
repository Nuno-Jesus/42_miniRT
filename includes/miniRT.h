/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:01:11 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/10 17:03:05 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# ifdef __APPLE__
#  include "../mlx_macos/mlx.h"
# else
#  include "../mlx_linux/mlx.h"
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

# include <X11/X.h>

#endif