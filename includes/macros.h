/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/14 19:09:42 by maricard         ###   ########.fr       */
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
# define UPGUIDE (t_vec3){0.0, 1.0, 0.0}

# define HAS_COMMAS '1'
# define HERE printf("HERE\n");

# define EPSILON 0.00001

# define X 0
# define Y 1
# define Z 2

# define R 0
# define G 1
# define B 2

# define WIDTH 1920
# define HEIGHT 1080
# define RATIO WIDTH/(float)HEIGHT

# define MAX_REFLECTIONS 2

# define ON_KEYPRESS 2
# define ON_CLOSE 17
# define KEYPRESS_MASK  (1L << 0)
# define CLOSE_MASK  (1L << 17)

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364

# define ERROR_COLOR_A		"Wrong color syntax for ambient lightning"
# define ERROR_COLOR_L		"Wrong color syntax for light source"
# define ERROR_SYNTAX		"Syntax: file format misconfiguration."
# define ERROR_FILENAME		"Invalid filename."
# define ERROR_EMPTY_MAP	"Empty map."
# define ERROR_NO_CAMERA	"No camera in the map."

#endif