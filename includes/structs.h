/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:20:18 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/03 13:18:54 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

# define PI 3.1415926535
# define RADIANS(deg) deg * PI / 180.0
# define DEGREES(rad) rad * 180.0 / PI

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
} t_color;

typedef struct s_lightsource
{
	t_vec3	origin;
	float	brightness;
	t_color color;
} t_lightsource;

typedef struct s_light
{	
	float	ratio;
	t_color color;
} t_light;

typedef struct s_camera
{
	t_vec3	origin;
	t_vec3	normal;
	float	fov;
} t_camera;

typedef struct s_sphere
{
	t_vec3	origin;
	float	radius;
	t_color	color;
} t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
	t_color	color;
} t_plane;

typedef struct s_cylinder
{
	t_vec3	origin;
	t_vec3	normal;
	float radius;
	float height;
	t_color	color;
} t_cylinder;

typedef struct s_root
{
	t_camera		camera;
	t_light			ambient;
	t_lightsource	*source;
	t_plane			*planes;
	t_sphere		*spheres;
	t_cylinder		*cylinders;
	int				num_sources;
	int				num_spheres;
	int				num_planes;
	int				num_cylinder;
	char			**map;
} t_root;

#endif