/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:39:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/05 14:07:42 by maricard         ###   ########.fr       */
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

# define PI 3.1415926535
# define RADIANS(deg) deg * PI / 180.0
# define DEGREES(rad) rad * 180.0 / PI

# define HAS_COMMAS '1'

# define X 0
# define Y 1
# define Z 2

# define R 0
# define G 1
# define B 2

# define ERROR_COLOR_A		"Wrong color syntax for ambient lightning"
# define ERROR_COLOR_L		"Wrong color syntax for light source"
# define ERROR_SYNTAX		"Syntax: file format misconfiguration."
# define ERROR_FILENAME		"Invalid filename."
# define ERROR_EMPTY_MAP	"Empty map."
# define ERROR_NO_CAMERA	"No camera in the map."

#endif