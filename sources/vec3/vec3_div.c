/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:09:41 by maricard          #+#    #+#             */
/*   Updated: 2023/08/17 13:10:02 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec3_div(t_vec3 v1, double scalar)
{
	return (vec3_new(v1.x / scalar, v1.y / scalar, v1.z / scalar));
}
