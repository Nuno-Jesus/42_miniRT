/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:01:30 by crypto            #+#    #+#             */
/*   Updated: 2023/08/10 13:35:12 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "miniRT.h"

void	ambient_print(t_light *s);

void	camera_print(t_camera *s);

void	light_print(t_light *l);

void	plane_print(t_plane *p);

void	sphere_print(t_sphere *s);

void	cylinder_print(t_cylinder *c);

void	shape_print(t_shape *shape);

void	color_print(t_color *color);

void	vec3_print(t_vec3 vec);

void	world_print(t_world *world);

#endif