/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/12 13:53:07 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H

# include "miniRT.h"

//! Planes

t_plane		plane_from_strings(char **tokens);

t_plane		plane_from_numbers(t_vec3 point, t_vec3 normal, t_color color);

bool		plane_intersect(t_plane *pl, t_ray *ray, t_hit *inter);

//! Spheres

t_sphere	sphere_from_strings(char **tokens);

bool		sphere_intersect(t_sphere *sp, t_ray *ray, t_hit *inter);

t_vec3		sphere_normal(t_hit *inter, t_ray *ray);

//! Cylinders

t_cylinder	cylinder_from_strings(char **tokens);

bool		cylinder_intersect(t_cylinder *cy, t_ray *ray, \
	t_hit *inter);

t_vec3		cylinder_normal(t_hit *inter, t_ray *ray);

//! Shapes

t_shape		*shape_new(void	*data, t_shape_type type, int id);

t_shape		*shape_copy(t_shape *shape);

t_vec3		shape_normal(t_hit *inter, t_ray *ray);

//! Lights

t_light		*light_new(char **point, char *ratio, char **color);

t_light		*light_copy(t_light *lightsource);

//! World

t_world		*world_new(void);

void		destroy_world(t_world **world);

#endif
