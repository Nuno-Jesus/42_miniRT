/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:23:25 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/07 18:13:10 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "miniRT.h"

int		render(t_root *r);

void	put_pixel(t_root *r, t_color c, int x, int y);

t_color	color_mult(t_color color, double k);

t_color	color_add(t_color c1, t_color c2);

t_color	diffuse(t_vec3 bulb, t_inter *inter, double k);

t_color	ambient(t_color	color, double ratio);

#endif