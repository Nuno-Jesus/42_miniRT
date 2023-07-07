/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:42:14 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/07 22:57:32 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	world_to_viewport(int x, int y)
{
	t_vec3	converted;
	float	width;
	float	height;

	width = WIDTH;
	height = HEIGHT;
	converted.x = (2.0f*x)/width - 1;
	converted.y = (2.0f*y)/height - 1;
	converted.z = 0;
	return (converted);
}

int	render(t_root *r)
{	
	(void)r;
	int	x;
	int	y;
	t_vec3	point;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			//! Convert coordinates from space to viewport
			//_ Make a ray using the new coordinates
			//* Trace the ray
			//? For each shape check for intersection
			/// Paint the pixel with the color from the trace
			point = world_to_viewport(x, y);
			#ifdef DEBUG
				vec3_debug(point);
				printf("X: %d, Y: %d\n", x, y);
			#endif
		}
	}
	return (0);
}