/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:06:25 by crypto            #+#    #+#             */
/*   Updated: 2023/08/14 17:06:49 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "miniRT.h"

t_color	color_new(int r, int g, int b);

t_color	color_mult(t_color color, double k);

t_color	color_add(t_color c1, t_color c2);

t_color	color_from_strings(char **rgb);

#endif