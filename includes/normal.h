/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:39:15 by maricard          #+#    #+#             */
/*   Updated: 2023/08/09 15:03:17 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H

# include "miniRT.h"

t_vec3	normal(t_inter *inter, t_ray *ray);

t_vec3	sphere_normal(t_inter *inter, t_ray *ray);

t_vec3	cylinder_normal(t_inter *inter, t_ray *ray);

#endif