/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:23:25 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/14 17:42:01 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "miniRT.h"

int		render(t_world *w);

void	put_pixel(t_world *w, t_color c, int x, int y);

void	illuminate(t_world *world, t_hit *closest);

t_color	ambient(t_color	color, double ratio);

t_color	diffuse(t_light *bulb, t_hit *inter, double k);

bool	is_obscured(t_vector *shapes, t_shape *own, t_ray *ray, double max_t);

bool	is_shadowed(t_world *world, t_hit *closest);

/**
 * @brief Initializes the scene's viewport (what the camera can see) 
 * 
 * @param w The t_world struct
 */
void	init_viewport(t_world *w);

t_vec3	pixels_to_viewport(int x, int y);

t_ray	make_ray(t_world *w, t_vec3 factors);

t_vec3	ray_at(t_ray *ray, double t);

#endif