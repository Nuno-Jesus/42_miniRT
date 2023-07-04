/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:44:02 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/04 17:30:08 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

t_vec3	vec3_new(float x, float y, float z);

t_vec3	vec3_add(t_vec3 v1, t_vec3 v2);

t_vec3	vec3_sub(t_vec3 v1, t_vec3 v2);

float	vec3_mod(t_vec3 vec);

float	vec3_dot(t_vec3 v1, t_vec3 v2);

t_vec3	vec3_cross(t_vec3 v1, t_vec3 v2);

t_vec3	vec3_norm(t_vec3 vec);

void	vec3_debug(t_vec3 vec);

#endif