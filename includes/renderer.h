/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:23:25 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 21:30:23 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "miniRT.h"

int		render(t_world *r);

void	put_pixel(t_world *r, t_color c, int x, int y);

t_color	diffuse(t_light* bulb, t_intersection *inter, double k);

t_color	ambient(t_color	color, double ratio);

t_vec3	ray_at(t_ray *ray, double t);

t_vec3	world_to_viewport(int x, int y);

t_ray	make_ray(t_world *r, t_vec3 factors);

t_vec3	ray_at(t_ray *ray, double t);

t_color	calculate_global_illumination(t_light *bulb, t_intersection *closest, t_light *amb_light);


#endif