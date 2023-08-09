/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 19:58:11 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

//! Debug related macros

# define DEBUG
# define HERE printf("HERE\n");

//! Parsing macros

# define X 0
# define Y 1
# define Z 2

# define R 0
# define G 1
# define B 2

# define HAS_COMMAS '1'

# define ERROR_COLOR_A		"Wrong color syntax for ambient lightning"
# define ERROR_COLOR_L		"Wrong color syntax for light source"
# define ERROR_SYNTAX		"Syntax: file format misconfiguration."
# define ERROR_FILENAME		"Invalid filename."
# define ERROR_EMPTY_MAP	"Empty map."
# define ERROR_NO_CAMERA	"No camera in the map."

//! Math macros 

# define PI 3.1415926535f
# define RADIANS(deg) ((deg * PI) / 180.0f)
# define DEGREES(rad) ((rad * 180.0f) / PI)
# define EPSILON 0.0001

//! Fixed t_color structs

# define BLUE		(t_color){0, 0, 0, 255}
# define BLACK		(t_color){0, 0, 0, 0}
# define WHITE		(t_color){0, 255, 255, 255}
# define RED		(t_color){0, 255, 0, 0}

//! Fixed t_vec3 structs

# define UPGUIDE	(t_vec3){0.0, 1.0, 0.0}

//! Viewport and window macros

# ifdef __APPLE__
#  define WIDTH 800
# else
#  define WIDTH 640
# endif

# define RATIO 	(16.0/9.0)
# define HEIGHT (WIDTH/RATIO)

//! Minilibx events

# define ON_KEYPRESS 2
# define ON_CLOSE 17
# define KEYPRESS_MASK  (1L << 0)
# define CLOSE_MASK  (1L << 17)

# ifdef __APPLE__
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define C 8
#  define V 9
# else
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define C 99
#  define V 118
# endif

#endif