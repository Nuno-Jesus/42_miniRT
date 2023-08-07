/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:05:45 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/07 16:36:20 by crypto           ###   ########.fr       */
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

t_vec3	ray_at(t_ray *ray, double t)
{
	t_vec3	res;

	res = vec3_add(ray->origin, vec3_scale(ray->direction, t));
	return (res);
}

bool	intersects(t_shape *shape, t_ray *ray, t_inter *inter)
{
	bool	hit;

	hit = false;
	if (shape->type == SPHERE)
		hit = sphere_intersect(&shape->data.sp, ray, inter);
	else if (shape->type == PLANE)
		hit = plane_intersect(&shape->data.pl, ray, inter);
	else if (shape->type == CYLINDER)
		hit = cylinder_intersect(&shape->data.cy, ray, inter);
	if (hit)
	{
		inter->shape = shape;
		inter->point = ray_at(ray, inter->t);
		inter->normal = vec3_normalize(inter->normal);
	}
	return (hit);
}

bool	world_hit(t_shape *shapes, t_ray *ray, t_inter *inter)
{
	t_shape		*shape;
	t_inter		tmp;
	uint32_t	i;

	i = -1;
	while(++i < shapes->size)
	{
		shape = nc_vector_at(shapes, i);
		if (!intersects(shape, &ray, &tmp))
			continue;
		if (!inter->shape || tmp.t < inter->t)
			*inter = tmp;
	}
	return (inter->shape != NULL);
}

int	render(t_root *r)
{	
	t_vec3	coords;
	t_vec3	factors;
	t_ray	ray;
	t_inter	inter;
	t_color color;
	
	nc_bzero(&inter, sizeof(t_inter));
	coords.y = -1;
	while (++coords.y < HEIGHT)
	{
		coords.x = -1;
		while (++coords.x < WIDTH)
		{
			factors = world_to_viewport(coords.x, coords.y); 	// Convert pixels to viewport coords (V point)
			ray = make_ray(r, factors);					// Make a ray from camera to V
			if (world_hit(r->shapes, &ray, &inter))
				color = color_add(ambient(inter.color, r->ambient.ratio), \
					diffuse(&ray, inter.color, (t_vec3){0, 1, 1}, KDIFFUSE));
			put_pixel(r, ray.color, coords.x, coords.y);
			// color_print(&ray.color);
		}
	}
	mlx_put_image_to_window(r->disp.mlx, r->disp.win, r->disp.img, 0, 0);
	return (0);
}
