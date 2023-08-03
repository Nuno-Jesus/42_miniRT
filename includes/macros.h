/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/03 15:13:08 by crypto           ###   ########.fr       */
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

// # define DEBUG

# define PI 3.1415926535f
# define RADIANS(deg) ((deg * PI) / 180.0f)
# define DEGREES(rad) ((rad * 180.0f) / PI)

# define BLUE		(t_color){0, 0, 0, 255}
# define BLACK		(t_color){0, 0, 0, 0}
# define WHITE		(t_color){0, 255, 255, 255}
# define RED		(t_color){0, 255, 0, 0}
# define UPGUIDE	(t_vec3){0.0, 1.0, 0.0}

# define HAS_COMMAS '1'
# define HERE printf("HERE\n");

# define EPSILON 0.0001
# define KDIFFUSE 0.8

# define X 0
# define Y 1
# define Z 2

# define R 0
# define G 1
# define B 2

# ifdef __APPLE__
#  define WIDTH 800
#  define HEIGHT 500
# else
#  define WIDTH 1920
#  define HEIGHT 1080
# endif

# define RATIO WIDTH/(double)HEIGHT

# define MAX_REFLECTIONS 2

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
#  define UP 126
#  define DOWN 125
#  define C 8
#  define V 9
# else
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define UP 65362
#  define DOWN 65364
#  define C 99
#  define V 118
# endif

# define ERROR_COLOR_A		"Wrong color syntax for ambient lightning"
# define ERROR_COLOR_L		"Wrong color syntax for light source"
# define ERROR_SYNTAX		"Syntax: file format misconfiguration."
# define ERROR_FILENAME		"Invalid filename."
# define ERROR_EMPTY_MAP	"Empty map."
# define ERROR_NO_CAMERA	"No camera in the map."

#endif