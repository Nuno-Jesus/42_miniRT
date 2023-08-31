/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:04:41 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/31 15:52:22 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "miniRT.h"

/**
 * @brief funtion that prints the given error message as parameter and exits
 * the program destroying the world struct (freeing all the memory 
 * previously allocated)
 * 
 * @param world t_world struct with all the information of the world 
 * @param text text to be printed
 */
void	message(t_world *world, char *text);

void	display(t_world *w, t_xy xy, int color, char *text);

double 	closest_value(double t1, double t2);

void	compute_shapes_constants(t_vector *shapes);

/**
 * @brief this function checks how many intersections the ray has with the
 * object.
 * 
 * @param eq t_equation struct with the equation information
 * @return number of intersections, -1 if there are no intersections
 */
double	determinant(t_equation *eq);

/**
 * @brief this function will solve the quadratic equation, store the results
 * inside the t_equation struct (t1 and t2 variables) and return the number 
 * of intersections the ray has with the object.
 * 
 * @param eq t_equation struct with the equation information
 * @return number of intersections, -1 if there are no intersections
 */
double	solve(t_equation *eq);

#endif