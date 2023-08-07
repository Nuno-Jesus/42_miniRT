/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:39:15 by maricard          #+#    #+#             */
/*   Updated: 2023/08/07 16:03:07 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_H
# define NORMAL_H

# include "miniRT.h"

void	normal(t_inter *inter, t_ray *ray);

void	plane_normal(t_inter *inter, t_plane *pl, t_ray *ray);

void	sphere_normal(t_inter *inter, *ray);

#endif