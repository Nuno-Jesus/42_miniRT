/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:20:18 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/14 17:39:43 by maricard         ###   ########.fr       */
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

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_lightsource
{
	t_vec3	origin;
	float	brightness;
	t_color	color;
}	t_lightsource;

typedef struct s_light
{
	float	ratio;
	t_color	color;
}	t_light;

typedef struct s_camera
{
	t_vec3	origin;
	t_vec3	normal;
	float	fov;
}	t_camera;

typedef struct s_sphere
{
	t_vec3	origin;
	float	radius;
	t_color	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	point;
	t_vec3	normal;
	t_color	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	center;
	t_vec3	normal;
	float	radius;
	float	height;
	t_color	color;
}	t_cylinder;

typedef union u_data
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
} t_data;

typedef struct s_shape
{
	t_data			data;
	t_shape_type	type;
}t_shape;

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

typedef struct s_ray
{
	float   distance;
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_root
{
	t_camera		camera;
	t_light			ambient;
	t_vector		*sources;
	t_vector		*shapes;
	t_graphics		disp;
	char			**map;
	float			hview; //! Height of the viewport
	float			wview; //! Width of the viewport
	t_vec3			up;
	t_vec3			right;	
}	t_root;

#endif