/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:42:14 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/10 19:16:49 by ncarvalh         ###   ########.fr       */
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

// t_vec3	get_normal(t_shape type, void *shape)
// {
// 	t_vec3	normal;

	
// 	return (normal);
// }

// void	helper(t_vector *shapes, t_ray ray, t_shape type, int depth)
// {
// 	uint32_t	i;
// 	t_vec3		intersection;
// 	t_vec3		normal;
// 	t_ray		reflected;
	
// 	i = -1;
// 	while (++i < r->shapes.size)
// 	{
// 		if (!intersects(nc_vector_at(r->shapes, i), ray, &intersection))
// 			continue ;
// 		// R=2(N⋅L)N-L
// 		normal = get_normal(type, nc_vector_at(r->shapes, i));
// 		reflected = vec3_dot(normal, ray.direction);
// 		reflected = vec3_scale(reflected, 2);
// 		reflected = vec3_dot(reflected, normal);
// 		reflected = vec3_sub(reflected, ray.direction);
// 		trace(shapes, r, reflected, depth + 1);
// 	}
// }

// void	trace(t_root *r, t_ray ray, int depth)
// {
// 	if (depth == MAX_REFLECTIONS)
// 		return ;
// 	helper(r->planes, ray, PLANE, depth);
// 	helper(r->spheres, ray, SPHERE, depth);
// 	helper(r->cylinders, ray, CYLINDER, depth);
// }

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
			// trace(r, ray);
			//* Trace the ray
			//? For each shape check for intersection
			if (sphere_intersect(nc_vector_at(r->spheres, 0), &ray))
			{
				// HERE;
				put_pixel(r, (t_color){0, 255, 0, 255}, x, y);
			}
			else
				put_pixel(r, (t_color){0, 255, 0, 0}, x, y);
			/// Paint the pixel with the color from the trace
		}
	}
	printf("\n\t ENDED \n\n");
	mlx_put_image_to_window(r->disp.mlx, r->disp.win, r->disp.img, 0, 0);
	return (0);
}