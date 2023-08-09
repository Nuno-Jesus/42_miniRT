/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 21:35:53 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H

# include "miniRT.h"

//! Planes

t_plane		plane_new(char **point, char **normal, char **color);

bool		plane_intersect(t_plane *pl, t_ray *ray, t_intersection *inter);

//! Spheres

t_sphere	sphere_new(char **center, char *diameter, char **color);

bool		sphere_intersect(t_sphere *sp, t_ray *ray, t_intersection *inter);

t_vec3		sphere_normal(t_intersection *inter, t_ray *ray);

//! Cylinders

t_cylinder	cylinder_new(char **tokens);

bool		cylinder_intersect(t_cylinder *cy, t_ray *ray, t_intersection *inter);

t_vec3		cylinder_normal(t_intersection *inter, t_ray *ray);

//! Shapes

t_shape		*shape_new(void	*data, t_shape_type type);

t_shape		*shape_copy(t_shape *shape);

t_vec3		shape_normal(t_intersection *inter, t_ray *ray);

//! Lights

t_light		*light_new(char **point, char *ratio, char **color);

t_light		*light_copy(t_light *lightsource);

//! World

t_world		*world_new(void);

void		destroy_world(t_world **world);

#endif
