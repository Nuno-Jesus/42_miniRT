/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:20:18 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/07 22:24:20 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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

typedef struct s_graphics {
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
	t_vec3	origin;
	t_vec3	direction;
}	t_ray;

typedef struct s_root
{
	t_camera		camera;
	t_light			ambient;
	t_vector		*sources;
	t_vector		*planes;
	t_vector		*spheres;
	t_vector		*cylinders;
	t_graphics		disp;
	char			**map;
	float			hview; //! Height of the viewport
	float			wview; //! Width of the viewport
}	t_root;

#endif