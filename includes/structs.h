/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:20:18 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/13 21:03:54 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum s_shape_type
{
	PLANE,
	SPHERE,
	CYLINDER,
}	t_shape_type;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_equation
{
	double	a;
	double	b;
	double	c;
	double	t1;
	double	t2;
}	t_equation;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_light
{
	t_vec3	center;
	double	ratio;
	t_color	color;
}	t_light;

typedef struct s_camera
{
	t_vec3	center;
	t_vec3	normal;
	double	fov;
}	t_camera;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	center;
	t_vec3	normal;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	cap1;
	t_vec3	cap2;
	t_vec3	normal;
	double	radius;
	double	height;
	t_color	color;
}	t_cylinder;

typedef union u_data
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
}	t_data;

typedef struct s_shape
{
	t_data			data;
	t_shape_type	type;
	int				id;
}	t_shape;

typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		line_length;
	int		endian;
}	t_graphics;

typedef struct s_hit
{
	t_shape	*shape;
	t_ray	ray;
	t_vec3	point;
	t_vec3	normal;
	t_color	color;
	t_vec3	a;
	double	t;
}	t_hit;

typedef struct s_world
{
	t_camera	camera;
	t_light		ambient;
	t_vector	*lights;
	t_vector	*shapes;
	int			counters[3];
	t_graphics	disp;
	t_vec3		up;
	t_vec3		right;
	char		**map;
	double		hview;
	double		wview;
}	t_world;

#endif