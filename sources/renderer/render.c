/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:05:45 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/05 15:42:48 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	world_to_viewport(int x, int y)
{
	t_vec3	converted;
	double	width;
	double	height;

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
	res = vec3_add(res, r->camera.origin);
	ray.origin = r->camera.origin;
	ray.direction = vec3_sub(res, ray.origin);
	ray.distance = INFINITY;
	ray.color = BLACK;
	return (ray);
}
//_ R=2(N⋅L)N-L

bool	intersects(t_shape *shape, t_ray *ray)
{
	if (shape->type == SPHERE)
		return (sphere_intersect(&shape->data.sp, ray));
	else if (shape->type == PLANE)
		return (plane_intersect(&shape->data.pl, ray));
	else if (shape->type == CYLINDER)
		return (cylinder_intersect(&shape->data.cy, ray));
	return (false);
}
/*
typedef struct s_inter
{
	t_shape	*shape;
	t_vec3	point;
	t_vec3	normal;
}t_inter;
*/
int	render(t_root *r)
{	
	t_vec3	coords;
	t_vec3	factors;
	t_ray	ray;
	t_shape	*shape;
	// t_inter	inter;
	bool	hit;
	
	coords.y = -1;
	while (++coords.y < HEIGHT)
	{
		coords.x = -1;
		while (++coords.x < WIDTH)
		{
			// Convert pixels to viewport coords (V point)
			factors = world_to_viewport(coords.x, coords.y);
			// Make a ray from camera to V
			ray = make_ray(r, factors);
			// World hit function
			// {
			for (uint32_t i = 0; i < r->shapes->size; i++)
			{
				shape = nc_vector_at(r->shapes, i);
				hit = intersects(shape, &ray);
				if (!hit)
					continue;
				ray.color = color_add(ambient(ray.color, r->ambient.ratio), \
					diffuse(&ray, ray.color, vec3_normalize((t_vec3){0, 1, 1}), KDIFFUSE));
				
			}
			// }
			// if (!world_hit(r->shapes, ray, inter));
			// 	ray.color = BLACK;
			// else
			// {
			//	ray.color = ambient + diffuse + reflect(inter.shape, ray, )
			// }
			put_pixel(r, ray.color, coords.x, coords.y);
			// color_print(&ray.color);
		}
	}
	mlx_put_image_to_window(r->disp.mlx, r->disp.win, r->disp.img, 0, 0);
	return (0);
}
