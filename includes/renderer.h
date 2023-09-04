/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:23:25 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/04 15:15:33 by crypto           ###   ########.fr       */
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
 * However, this function only operates between the boundaries set on 
 * the t_runner struct. This is the routine all threads run in parallel
 * to achieve the final image.
 * 
 * @param worker A thread runner struct. Contains the thread's id and
 * the boundaries it should operate in.
 * @return NULL
 */
void	*render(t_runner *worker);

/**
 * @brief Given all the scene's shapes and the casted ray, it asserts
 * if the ray ever hit one of the shapes. If so, the closest struct will
 * be filled with a pointer to the closest hit shape, among other 
 * useful variables.
 * 
 * @param shapes The scene's shapes
 * @param ray The casted ray
 * @param closest The closest hit shape
 * @return true If it hit something
 * @return false Otherwise
 */
bool	world_hit(t_vector *shapes, t_ray *ray, t_hit *closest);

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
 * 		 Ia = Ka * ShapeColor
 * 
 * Ia - ambient color
 * Ka - ratio of ambient lighting in the scene
 * ShapeColor - the closest shape color
 * 
 * @param ambient The ambient light struct
 * @param color The shape's color
 * @return t_color The final color
 */
t_color	ambient(t_light *ambient, t_color color);

/**
 * @brief Calculates the diffuse lighting in a shape. The 
 * diffuse lighting is calculated by the following formula:
 * 
 * 		Id = Kd * Ip * cos(A) * ShapeColor
 * 
 * Id - diffuse color
 * Kd - ratio of diffuse lighting in the scene
 * Ip - intensity of the light source
 * A - angle between the normal at the intersection point and the 
 * light direction
 * cos(A) - cosine of A
 * ShapeColor - the closest shape's color
 * 
 * @param bulb The light source
 * @param inter The closest shape information
 * @return t_color The final color
 */
t_color	diffuse(t_light *bulb, t_hit *inter);

/**
 * @brief Calculates the specular lighting in a given point
 * 
 * The specular lighting in a given point is calculated given the 
 * following formula
 * 
 * 		Ie = Ke * Ip * (N.H)^n
 * 
 * Ie - specular lighting
 * Ke - specular constant (depends on the material)
 * Ip - light source intensity 
 * H - half vector (the normalized vector between the light and 
 *  camera directions)
 * N - the normal vector in that surface
 * n - a value depending on the material (high for highly polished 
 * surfaces)
 * 
 * @param bulb The light source
 * @param closest The closest shape information
 * @return t_color The final color
 */
t_color	specular(t_light *bulb, t_hit *closest);

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
 * @param bulb The light source
 * @param closest The closest shape
 * @return The is_obscured return value
 */
bool	is_shadowed(t_world *world, t_light *bulb, t_hit *closest);

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

/**
 * @brief If a shape is textured, this function will apply such texture.
 * In this case, we're only handling checkerboard texture and only
 * on planes.
 * 
 * @param closest The closest structure with info about the intersection point 
 */
void	apply_texture(t_hit *closest);

/**
 * @brief The callback used on a relevant keypress. Launches N threads
 * to render the scene and assigns each one with a screen zone to render.
 * 
 * @param world The t_world struct
 */
void	multithread(t_world *world);

#endif