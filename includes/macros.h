/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/22 10:57:51 by crypto           ###   ########.fr       */
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
# include <pthread.h>

//! Debug related macros

# define DEBUG
# define HERE 		printf("HERE\n");

//! Parsing macros

# define X 0
# define Y 1
# define Z 2

# define R 0
# define G 1
# define B 2

# define HAS_COMMAS '1'

# define ERROR(m)	\
	printf("Error\n%s\n", m)
# define ERROR_NUM_ARGS(x, n)		\
	ERROR("Wrong number of args in "x" (need "n")")
# define ERROR_NUM_COMMAS(x)		\
	ERROR("Too many/few commas in "x)
# define ERROR_MISFORMAT_COLOR(x)	\
	ERROR("Colors misformatting in "x)
# define ERROR_AMBIENT_RATIO_OUT_OF_BOUNDS		\
	ERROR("Ambient coefficient out of bounds [0.0,1.0]")
# define ERROR_CAMERA_FOV_OUT_OF_BOUNDS			\
	ERROR("FOV coefficient out of bounds [0.0,1.0]")
# define ERROR_LIGHT_BRIGHTNESS_OUT_OF_BOUNDS	\
	ERROR("Light brightness out of bounds [0.0,1.0]")
# define ERROR_KS_OUT_OF_BOUNDS(x)				\
	ERROR("Specular coefficient out of bounds in "x" [0.0,1.0]")
# define ERROR_SHININESS_OUT_OF_BOUNDS(x)		\
	ERROR("Shininess out of bounds in "x" [0.0,+∞[")
# define ERROR_VALUES_TOO_SMALL(x)				\
	ERROR("Values are too small in "x)
# define ERROR_UNKNOWN_SHAPE				\
	ERROR("Unknown shape to apply texture")

# define ERROR_SYNTAX		"Syntax: file format misconfiguration."
# define ERROR_NOT_BER		"File extension is not '.ber'."
# define ERROR_OPEN_FILE	"Couldn't open requested file"
# define ERROR_EMPTY_MAP	"Empty map."
# define ERROR_NO_CAMERA	"No camera in the map."
# define ERROR_TOO_MANY		"Found more than 1 A or C entities"
# define ERROR_MALLOC(str)  "Failed allocation on "str"."
# define ERROR_USAGE 		"Usage: ./miniRT <scene>.rt"

//! Math macros 

# define PI 3.1415926535f
# define RADIANS(deg) ((deg * PI) / 180.0f)
# define DEGREES(rad) ((rad * 180.0f) / PI)
# define EPSILON 0.0001

//! Fixed t_color structs

# define WHITE		(t_color){0, 255, 255, 255}
# define BLACK		(t_color){0, 0, 0, 0}
# define BLUE		(t_color){0, 0, 0, 255}
# define RED		(t_color){0, 255, 0, 0}

//! Fixed t_vec3 structs

# define UPGUIDE		(t_vec3){0.0, 1.0, 0.0}
# define VEC_EPSILON	(t_vec3){EPSILON, EPSILON, EPSILON}

//! Viewport and window macros

# ifdef __APPLE__
#  define WIDTH 800
# else
#  define WIDTH 1920
# endif

# define RATIO 	(16.0/9.0)
# define HEIGHT (WIDTH/RATIO)

//! Minilibx events

# ifdef __APPLE__
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define C 8
#  define V 9
#  define KeyPress 2
#  define KeyPressMask (1L<<0)
#  define DestroyNotify 17
#  define StructureNotifyMask (1L<<17)
# else
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define C 99
#  define V 118
# endif

# define NUM_THREADS 8
# define THREADABLE

# define KD 0.8

#endif