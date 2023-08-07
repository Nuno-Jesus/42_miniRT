/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:39:15 by maricard          #+#    #+#             */
/*   Updated: 2023/08/07 17:35:09 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H

# include "miniRT.h"

t_vec3	normal(t_inter *inter, t_ray *ray);

t_vec3	sphere_normal(t_inter *inter, t_ray *ray);

#endif