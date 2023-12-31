/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:23:25 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/14 18:05:45 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "miniRT.h"

/**
 * @brief The function that renders the scene. Iterates over the scene's
 * pixels and traces a ray for each that will be used to collide with 
 * the world. The pixels are painted one by one until the final image
 * is rendered.
 * 
 * @param w The t_world struct 
 * @return int (dummy value)
 */
int		render(t_world *w);

/**
 * @brief Puts a pixel in an image with the given color and at the given
 * coordinates
 * 
 * @param w The t_world struct
 * @param c The pixel's color
 * @param x The horizontal displacement
 * @param y The vertical displacement
 */
void	put_pixel(t_world *w, t_color c, int x, int y);

/**
 * @brief Responsible to calculate the illumination in a given shape. 
 * The final illumination is given by the following formula:
 * 
 * 		I = Ia + Id
 * 
 * Ia - ambient lighting
 * Id - diffuse lighting
 * 
 * @param world The t_world struct
 * @param closest The closest intersected shape
 */
void	illuminate(t_world *world, t_hit *closest);

/**
 * @brief Calculates the ambient lighting in a shape. The 
 * ambient lighting is calculated by the following formula:
 * 
 * 		Ia = Ka * ShapeColor
 * 
 * Ia - ambient color
 * Ka - ratio of ambient lighting in the scene
 * ShapeColor - the closest shape color
 * 
 * @param color The closest shape's color
 * @param ratio The ambient lighting ration in the scene
 * @return t_color The final color
 */
t_color	ambient(t_color	color, double ratio);

/**
 * @brief Calculates the diffuse lighting in a shape. The 
 * diffuse lighting is calculated by the following formula:
 * 
 * 		Id = Kd * cos(A) * ShapeColor
 * 
 * Id - diffuse color
 * Kd - ratio of diffuse lighting in the scene
 * A - angle between the normal at the intersection point and the 
 * light direction
 * cos(A) - cosine of A
 * ShapeColor - the closest shape's color
 * 
 * @param color The closest shape color
 * @param ratio The ambient lighting ration in the scene
 * @return t_color The final color
 */
t_color	diffuse(t_light *bulb, t_hit *inter, double k);

/**
 * @brief Looks if any object is between the closest shape and the 
 * light source at the intersection point. The closest shape is 
 * disregarded in the comparisons.
 * 
 * @param shapes The shapes vector
 * @param own The shape to be disregarded
 * @param ray The light direction (from the intersection point)
 * @param max_t The maximum distance, which is the light source distance
 * @return true If any object is between the light and the closest shape
 * @return false Otherwise
 */
bool	is_obscured(t_vector *shapes, t_shape *own, t_ray *ray, double max_t);

/**
 * @brief Performs some calculations before calling the is_obscured function
 * like the light direction and distance 
 * 
 * @param world The t_world struct
 * @param closest The closest shape
 * @return The is_obscured return value
 */
bool	is_shadowed(t_world *world, t_hit *closest);

/**
 * @brief Initializes the scene's viewport (what the camera can see). The 
 * viewport will be supported by 3 vectors: up, right and forward.
 * Together, those vectors can return any point on the plane. 
 * 
 * @param w The t_world struct
 */
void	init_viewport(t_world *w);

/**
 * @brief Converts a pixel in x (0 to width - 1) and y (0 to height - 1) to
 * viewport x and viewport y factors (between -1 and 1). These factors are used 
 * with the viewport vectors to access any point.
 * 
 * @param x The pixel's x coordinate
 * @param y The pixel's y coordinate
 * @return t_vec3 The x and y viewport factors
 */
t_vec3	pixels_to_viewport(int x, int y);

/**
 * @brief Casts an infinite ray in space from the camera with the direction 
 * of one of the viewport's point.
 * 
 * @param w The t_world struct
 * @param factors The viewport factors
 * @return t_ray The casted ray
 */
t_ray	make_ray(t_world *w, t_vec3 factors);

/**
 * @brief Returns the point in the given ray with t direction vectors. A ray's
 * equation is given by:
 * 
 * 		P = O + tD
 * 
 * P - The point at t direction vectors
 * O - The ray's origin
 * t - Distance factor
 * D - The ray' direction
 * 
 * @param ray The casted ray
 * @param t The distance factor
 * @return t_vec3 The point at t
 */
t_vec3	ray_at(t_ray *ray, double t);

#endif