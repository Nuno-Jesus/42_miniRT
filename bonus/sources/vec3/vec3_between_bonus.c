/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_between.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:25:35 by crypto            #+#    #+#             */
/*   Updated: 2023/09/04 14:39:59 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	vec3_between(t_vec3 vec, t_vec3 min, t_vec3 max)
{
	return (
		(min.x <= vec.x && vec.x <= max.x) && \
		(min.y <= vec.y && vec.y <= max.y) && \
		(min.z <= vec.z && vec.z <= max.z)
	);
}
