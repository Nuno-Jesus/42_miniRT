/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:39:15 by maricard          #+#    #+#             */
/*   Updated: 2023/08/09 19:21:45 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H

# include "miniRT.h"

t_vec3	normal(t_intersection *inter, t_ray *ray);

t_vec3	sphere_normal(t_intersection *inter, t_ray *ray);

t_vec3	cylinder_normal(t_intersection *inter, t_ray *ray);

#endif