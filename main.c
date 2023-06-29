/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 15:48:24 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "miniRT.h"

int main(void)
{
	t_vec3 v1 = vector_new(6, -4, 5);
	t_vec3 v2 = vector_new(2, 1, 3);
	t_vec3 v3;

	vector_debug(v1);
	vector_debug(v2);
	printf("---------------------------------\n");
	v3 = vector_add(v1, v2);
	vector_debug(v3);
	printf("---------------------------------\n");

	v3 = vector_sub(v1, v2);
	vector_debug(v3);
	printf("---------------------------------\n");

	//Print the norm for vector 1
	printf("Norm of v1: %f\n", vector_mod(v1));

	//Print the dot product of vector 1 and 2
	printf("Dot product of v1 and v2: %f\n", vector_dot(v1, v2));

	//Print the cross product of vector 1 and 2
	v3 = vector_cross(v1, v2);
	vector_debug(v3);
	printf("---------------------------------\n");

	//Print the normalized vector 1
	v3 = vector_norm(v1);
	vector_debug(v3);
	printf("Module of v3: %f\n", vector_mod(v3));

	
	return (0);	
}