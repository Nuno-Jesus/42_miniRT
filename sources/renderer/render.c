/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:05:45 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 21:27:24 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	intersects(t_shape *shape, t_ray *ray, t_intersection *inter)
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
		inter->ray = *ray;
		inter->shape = shape;
		inter->point = ray_at(ray, inter->t);
		inter->normal = vec3_normalize(shape_normal(inter, ray));
	}
	return (hit);
}

bool	world_hit(t_vector *shapes, t_ray *ray, t_intersection *closest)
{
	t_shape		*shape;
	t_intersection		tmp;
	uint32_t	i;

	i = -1;
	nc_bzero(&tmp, sizeof(t_intersection));
	while(++i < shapes->size)
	{
		shape = nc_vector_at(shapes, i);
		if (!intersects(shape, ray, &tmp))
			continue;
		if (!closest->shape || tmp.t < closest->t + EPSILON)
			*closest = tmp;
	}
	if (closest->shape)
		return (true);
	return (false);
}

bool	reflected(t_light *light, t_intersection *closest)
{
	t_vec3 reflection;
	t_vec3 light_dir;
	double cossine;

	//2 * (N ⋅ L) * N - L
	light_dir = vec3_sub(light->center, closest->point);
	reflection = vec3_scale(closest->normal, 2 * vec3_dot(closest->normal, light_dir));
	reflection = vec3_sub(reflection, light_dir);
	reflection = vec3_normalize(reflection);
	cossine = vec3_cossine(light_dir, reflection);
	double angle;

	angle = DEGREES(acos(cossine));
	if (angle >= 0.0 - EPSILON && angle <= 180.0 + EPSILON)
	{
		// printf("Angle: %f\n", angle);
		return (true);
	}
	return (false);
}

int	render(t_world *r)
{	
	t_vec3	coords;
	t_vec3	factors;
	t_ray	ray;
	t_intersection	closest;
	t_color color;
	
	coords.y = -1;
	while (++coords.y < HEIGHT)
	{
		coords.x = -1;
		while (++coords.x < WIDTH)
		{
			color = BLACK;
			nc_bzero(&closest, sizeof(t_intersection));
			factors = world_to_viewport(coords.x, coords.y); 	// Convert pixels to viewport coords (V point)
			ray = make_ray(r, factors);					// Make a ray from camera to V
			if (world_hit(r->shapes, &ray, &closest))
				color = calculate_global_illumination(nc_vector_at(r->lights, 0), &closest, &r->ambient);	
			put_pixel(r, color, coords.x, coords.y);
		}
	}
	mlx_put_image_to_window(r->disp.mlx, r->disp.win, r->disp.img, 0, 0);
	return (0);
}
