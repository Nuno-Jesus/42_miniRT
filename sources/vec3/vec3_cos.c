/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:44 by crypto            #+#    #+#             */
/*   Updated: 2023/08/03 15:22:12 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	vec3_cos(t_vec3 v1, t_vec3 v2)
{
	double	dot;
	double	lengths;

	dot = vec3_dot(v1, v2);
	lengths = vec3_module(v1) * vec3_module(v2);
	return (dot / lengths);
}