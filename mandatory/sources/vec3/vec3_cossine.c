/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cossine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:44 by crypto            #+#    #+#             */
/*   Updated: 2023/08/10 17:58:53 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	vec3_cossine(t_vec3 v1, t_vec3 v2)
{
	double	dot;
	double	lengths;

	dot = vec3_dot(v1, v2);
	lengths = vec3_length(v1) * vec3_length(v2);
	return (dot / lengths);
}
