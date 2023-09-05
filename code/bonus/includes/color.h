/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:06:25 by crypto            #+#    #+#             */
/*   Updated: 2023/08/31 18:38:36 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "miniRT.h"

/**
 * @brief Returns a new color with the given component values.
 * All components are clamped between 0 and 255.
 * 
 * @param r The red component  
 * @param g The green component
 * @param b The blue component
 * @return t_color The new color
 */
t_color	color_new(int r, int g, int b);

/**
 * @brief Given an existent color, it multiplies each component
 * by the parameter k, and returns the result. The final components
 * are clamped between 0 and 255.
 * 
 * @param color The color to change
 * @param k The parameter to multiply with
 * @return t_color The new color
 */
t_color	color_mult(t_color color, double k);

/**
 * @brief Adds two colors by addding each components.
 * The final components are clamped between 0 and 255.
 * 
 * @param c1 The first color
 * @param c2 The second color
 * @return t_color The final color
 */
t_color	color_add(t_color c1, t_color c2);

/**
 * @brief Given the original color and a color to mix with,
 * it blends both by multiplying each component of the original
 * color by the corresponding component of the mixer color.
 * Each mixer component is mapped to a value between 0 and 1
 * The final components are clamped between 0 and 255.
 * 
 * @param color The original color
 * @param mixer The color to blend with
 * @return t_color The final color
 */
t_color	color_mix(t_color color, t_color mixer);

/**
 * @brief Given an array of strings, where each string maps to a
 * component (rgb[0] is red, rgb[1] is green and rgb[2] is blue),
 * converts the strings into a new color struct. All components
 * values are clamped between 0 and 255.
 * 
 * @param rgb The string array containing the component's values
 * @return t_color The new color
 */
t_color	color_from_strings(char **rgb);

/**
 * @brief Given a color, it converts it to an int value.
 * 
 * @param color The RGB to convert to int
 * @return int The final integer value
 */
int		color_to_int(t_color color);

#endif