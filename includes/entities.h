/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/15 16:11:58 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H

# include "miniRT.h"

/**
 * @brief this function will check what type of shape it is and call the
 * respective function to check if the ray intersects with the shape  
 * 
 * @param shape cylinder, sphere or plane
 * @param ray struct with ray information
 * @param inter struct with intersection information
 * @return true if the ray intersects with the shape, false otherwise
 */
bool		intersects(t_shape *shape, t_ray *ray, t_hit *inter);

//! Planes
/**
 * @brief function that will create a plane and store it's information
 * from a string array
 * 
 * @param plane t_plane struct with plane information
 * @param tokens string array with plane information
 * @return true if the plane was created correctly, false otherwise
 */
bool		plane_from_strings(t_plane *plane, char **tokens);

/**
 * @brief this function will create a plane with the correponding information
 * 
 * @param point point in the plane
 * @param normal normal of the plane
 * @param color color of the plane
 * @return t_plane struct with plane information
 */
t_plane		plane_from_numbers(t_vec3 point, t_vec3 normal, t_color color);

/**
 * @brief this function will check if the ray intersects with the plane,
 * using the dot product of the ray direction and the plane normal. If the
 * dot product is not 0, then the ray intersects with the plane. If not, then
 * the ray is parallel to the plane and doesn't intersect with it.
 * 
 * @param pl t_plane struct with plane information
 * @param ray t_ray struct with ray information
 * @param inter t_hit struct with intersection information
 * @return true if the ray intersects with the plane, false otherwise 
 */
bool		plane_intersect(t_plane *pl, t_ray *ray, t_hit *inter);

//! Spheres
/**
 * @brief this function will create a sphere and store it's information
 * from a string array
 * 
 * @param sp t_sphere struct with sphere information
 * @param tokens string array with sphere information
 * @return true if the sphere was created correctly, false otherwise
 */
bool		sphere_from_strings(t_sphere *sp, char **tokens);

/**
 * @brief this function will check if the ray intersects with the sphere,
 * using the quadratic equation (solve function). If the determinant is
 * greater than 0, then the ray intersects with the sphere. If not, then
 * the ray doesn't intersect with it.
 * 
 * @param sp t_sphere struct with sphere information
 * @param ray t_ray struct with ray information
 * @param inter t_hit struct with intersection information
 * @return true if the ray intersects with the sphere, false otherwise 
 */
bool		sphere_intersect(t_sphere *sp, t_ray *ray, t_hit *inter);

/**
 * @brief this function will calculate the normal of the sphere in the
 * intersection point
 * 
 * @param inter t_hit struct with intersection information
 * @param ray t_ray struct with ray information
 * @return t_vec3 vector with the normal of the sphere in the intersection 
 * point
 */
t_vec3		sphere_normal(t_hit *inter, t_ray *ray);

//! Cylinders
/**
 * @brief this function will create a cylinder and store it's information
 * from a string array
 * 
 * @param cy t_cylinder struct with cylinder information
 * @param tokens string array with cylinder information
 * @return true if the cylinder was created correctly, false otherwise
 */
bool		cylinder_from_strings(t_cylinder *cy, char **tokens);

/**
 * @brief this function will check if the ray intersects with the cylinder,
 * using the quadratic equation (solve function) to discover the intersection
 * with the "walls" of the cylinder and the distance between the ray origin.
 * And then, using the dot product of the ray direction and the cylinder
 * normal, it will check if the ray intersects with the "caps" of the cylinder.
 * 
 * @param cy t_cylinder struct with cylinder information
 * @param ray t_ray struct with ray information
 * @param inter t_hit struct with intersection information
 * @return true if the ray intersects with the cylinder, false otherwise 
 */
bool		cylinder_intersect(t_cylinder *cy, t_ray *ray, t_hit *inter);

/**
 * @brief this function will calculate the 4 possible intersections of the
 * ray with the cylinder and store them in the equation struct. Then, it will
 * check if the ray intersects with the "walls" and "caps" of the cylinder and
 * store the closest intersection point in the intersection struct.
 * 
 * @param cy t_cylinder struct with cylinder information
 * @param ray t_ray struct with ray information
 * @param equation t_equation struct with intersection information
 * @param inter t_hit struct with intersection information
 * @return "t" value of the closest intersection point found
 */
double		verify_intersections(t_cylinder *cy, t_ray *ray, \
				t_equation *equation, t_hit *inter);

/**
 * @brief this function will check if the ray intersects with the "caps" of
 * the cylinder, using the plane_from_number function.
 * 
 * @param cy t_cylinder struct with cylinder information
 * @param ray t_ray struct with ray information
 * @param cap vector with the cap center point
 * @return "t" value of the intersection point with the "cap" of the cylinder
 */
double		cap_intersection(t_cylinder *cy, t_ray *ray, t_vec3 cap);

/**
 * @brief this function will check if the ray intersects with the "walls" of
 * the cylinder. Using the "t" value we will check if the intersection point
 * is inside the cylinder, comparing with the height and radius.
 * 
 * @param cy t_cylinder struct with cylinder information
 * @param inter t_hit struct with intersection information
 * @param t "t" value of the intersection point
 * @return true if the ray intersects with the "walls" of the cylinder and "t"
 * value is lower than the one found until now, false otherwise
 */
bool		check_walls(t_cylinder *cy, t_hit *inter, double t);

/**
 * @brief this function will check if the ray intersects with the "caps" of
 * the cylinder. Using the "t" value we will check if the intersection point
 * is inside on the cap of the cylinder, comparing his distance with the radius.
 * 
 * @param cy t_cylinder struct with cylinder information
 * @param cap center point of the cap
 * @param inter t_hit struct with intersection information
 * @param t "t" value of the intersection point
 * @return true if the ray intersects with the "caps" of the cylinder and "t"
 * value is lower than the one found until now, false otherwise
 */
bool		check_caps(t_cylinder *cy, t_vec3 cap, t_hit *inter, double t);

/**
 * @brief this function will calculate the normal of the cylinder in the
 * intersection point
 * 
 * @param inter t_hit struct with intersection information
 * @param ray t_ray struct with ray information
 * @return t_vec3 vector with the normal of the cylinder in the intersection 
 * point
 */
t_vec3		cylinder_normal(t_hit *inter, t_ray *ray);

//! Torus

bool	torus_from_strings(t_torus *to, char **tokens);

bool	torus_intersect(t_cylinder *to, t_ray *ray, t_hit *inter);

//! Shapes
/**
 * @brief this function will create the corresponding shape given in the
 * type parameter and store it's information on the shape struct
 * 
 * @param data struct with shape information
 * @param type type of the shape
 * @param id id of the shape (each shape has a unique id)
 * @return t_shape struct with shape information
 */
t_shape		*shape_new(void	*data, t_shape_type type, int id);

/**
 * @brief this function will copy the shape information from the shape
 * parameter to a new shape
 * 
 * @param shape t_shape struct with the shape information
 * @return t_shape struct with shape information
 */
t_shape		*shape_copy(t_shape *shape);

/**
 * @brief this function will check if what type of shape it is and call the
 * respective function to check what is the normal of the shape in the
 * intersection point
 * 
 * @param inter t_hit struct with intersection information
 * @param ray t_ray struct with ray information
 * @return t_vec3 vector with the normal of the shape in the intersection point
 */
t_vec3		shape_normal(t_hit *inter, t_ray *ray);

//! Lights
/**
 * @brief this function will create a light and store it's information
 * from a string array
 * 
 * @param point string array with light position
 * @param ratio string with light ratio
 * @param color string array with light color
 * @return t_light struct with light information
 */
t_light		*light_new(char **point, char *ratio, char **color);

/**
 * @brief this function will copy the light information from the lightsource
 * parameter to a new lightsource
 * 
 * @param lightsource t_light struct with the light information
 * @return t_light struct with new light information
 */
t_light		*light_copy(t_light *lightsource);

//! World
/**
 * @brief this function will create the world struct and initialize
 * all members of the struct.
 * 
 * 
 * @return t_world struct with root information
 */
t_world		*world_new(void);

/**
 * @brief this function will destroy the world struct and free all
 * members of the struct.
 * 
 * @param world t_world struct with root information
 */
void		destroy_world(t_world **world);

#endif
