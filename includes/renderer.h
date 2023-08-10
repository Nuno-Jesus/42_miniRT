/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:23:25 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/10 17:52:51 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "miniRT.h"

int		render(t_world *w);

void	put_pixel(t_world *w, t_color c, int x, int y);

t_color	diffuse(t_light *bulb, t_hit *inter, double k);

t_color	ambient(t_color	color, double ratio);

t_vec3	ray_at(t_ray *ray, double t);

t_vec3	pixels_to_viewport(int x, int y);

t_ray	make_ray(t_world *w, t_vec3 factors);

t_vec3	ray_at(t_ray *ray, double t);

void	illuminate(t_vector *lights, t_hit *closest, t_light *amb_light);

#endif