/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:44:02 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/07 17:44:01 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	vec3_new(double x, double y, double z);

t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);

t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2);

double	vec3_module(t_vec3 vec);

double	vec3_dot(t_vec3 v1, t_vec3 v2);

t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2);

t_vec3	vec3_normalize(t_vec3 vec);

void	vec3_print(t_vec3 vec);

t_vec3	vec3_scale(t_vec3 v1, double scalar);

double	vec3_cos(t_vec3 v1, t_vec3 v2);

#endif