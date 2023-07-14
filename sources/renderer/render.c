/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:42:14 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/14 15:32:30 by ncarvalh         ###   ########.fr       */
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

t_ray	make_ray(t_root *r, t_vec3 factors)
{
	t_ray	ray;
	t_vec3	vertical;
	t_vec3	horizontal;
	t_vec3	res;

	vertical = vec3_scale(r->up, factors.y * r->hview);
	horizontal = vec3_scale(r->right, factors.x * r->wview);
	res = vec3_add(vertical, horizontal);
	res = vec3_add(res, r->camera.normal);
	ray.origin = r->camera.origin;
	ray.direction = vec3_sub(res, ray.origin);
	return (ray);
}
//_ R=2(N⋅L)N-L

bool	intersects(t_shape *shape, t_ray *ray)
{
	if (shape->type == SPHERE)
		return (sphere_intersect(&shape->data.sp, ray));
	// else if (shape->type == PLANE)
	// 	return (plane_intersect(&shape->data.pl, ray));
	else if (shape->type == CYLINDER)
		return (cylinder_intersect(&shape->data.cy, ray));
	return (false);
}

int	render(t_root *r)
{	
	int	x;
	int	y;
	t_vec3	factors;
	t_ray	ray;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			factors = world_to_viewport(x, y);
			ray = make_ray(r, factors);
			for (uint32_t i = 0; i < r->shapes->size; i++)
			{
				bool hit;
				t_color	color = WHITE;
				t_shape	*shape = nc_vector_at(r->shapes, i);
				
				hit = intersects(shape, &ray);
				if (!hit)
					continue;
				if (shape->type == SPHERE)
					color = shape->data.sp.color;
				else if (shape->type == PLANE)
					color = shape->data.pl.color;
				else
					color = shape->data.cy.color;
				put_pixel(r, color, x, y);				
			}
		}
	}
	mlx_put_image_to_window(r->disp.mlx, r->disp.win, r->disp.img, 0, 0);
	return (0);
}