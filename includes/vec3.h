/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:44:02 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/14 13:07:43 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include "miniRT.h"

t_vec3	vec3_new(double x, double y, double z);

t_vec3	vec3_from_strings(char **vec);

t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);

t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2);

double	vec3_length(t_vec3 vec);

double	vec3_dot(t_vec3 v1, t_vec3 v2);

t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2);

t_vec3	vec3_normalize(t_vec3 vec);

t_vec3	vec3_scale(t_vec3 v1, double scalar);

double	vec3_cossine(t_vec3 v1, t_vec3 v2);

bool	vec3_compare(t_vec3 v1, t_vec3 v2);

#endif