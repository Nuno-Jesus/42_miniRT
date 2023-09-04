/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:44:02 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/04 15:16:40 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include "miniRT.h"

/**
 * @brief function to create a new vector with the given values
 * 
 * @param x value for x coordinate
 * @param y value for y coordinate
 * @param z value for z coordinate
 * @return vector(x, y, z)
 */
t_vec3	vec3_new(double x, double y, double z);

/**
 * @brief function to create a new vector from a string array
 * 
 * @param vec string array with the values of x, y and z coordinates
 * @return vector(x, y, z)
 */
t_vec3	vec3_from_strings(char **vec);

/**
 * @brief function to add two vectors
 * 
 * @param v1 first vector
 * @param v2 second vector
 * @return vector(x, y, z)
 */
t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);

/**
 * @brief function to subtract two vectors
 * 
 * @param v1 first vector
 * @param v2 second vector
 * @return vector(x, y, z)
 */
t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2);

/**
 * @brief function to calculate the length of a vector
 * 
 * @param vec vector
 * @return double
 */
double	vec3_length(t_vec3 vec);

/**
 * @brief function to calculate the dot product of two vectors
 * 
 * @param v1 first vector
 * @param v2 second vector
 * @return double
 */
double	vec3_dot(t_vec3 v1, t_vec3 v2);

/**
 * @brief function to calculate the cross product of two vectors
 * 
 * @param v1 first vector
 * @param v2 second vector
 * @return vector(x, y, z)
 */
t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2);

/**
 * @brief function to normalize a vector
 * 
 * @param vec vector
 * @return vector(x, y, z)
 */
t_vec3	vec3_normalize(t_vec3 vec);

/**
 * @brief function to scale a vector
 * 
 * @param v1 vector to be scaled
 * @param scalar scalar value
 * @return vector(x, y, z)
 */
t_vec3	vec3_scale(t_vec3 v1, double scalar);

/**
 * @brief function to calculate the cossine of two vectors
 * 
 * @param v1 first vector
 * @param v2 second vector
 * @return double
 */
double	vec3_cossine(t_vec3 v1, t_vec3 v2);

/**
 * @brief function to comapre two vectors
 * 
 * @param vec vector
 * @return true if the vectors are equal, false otherwise
 */
bool	vec3_compare(t_vec3 v1, t_vec3 v2);

/**
 * @brief rotates a vector around an axis. The result is a normalized
 * vector
 * 
 * @param vec The vector to rotate 
 * @param axis The axis to rotate around
 * @param angle The angle to rotate
 * @return t_vec3 The rotated vector
 */
t_vec3	vec3_rotate(t_vec3 vec, int axis, double angle);

/**
 * @brief Given a vector to compare with min and max, asserts if the
 * vec fields (x, y and z) are between min and max fields.
 * 
 * @param vec The vector to compare
 * @param min The min reference
 * @param max The max reference
 * @return true If the vector is between min and max
 * @return false Otherwise
 */
bool	vec3_between(t_vec3 vec, t_vec3 min, t_vec3 max);

#endif