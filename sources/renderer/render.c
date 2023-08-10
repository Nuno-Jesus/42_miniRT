/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:05:45 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/10 17:37:42 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	intersects(t_shape *shape, t_ray *ray, t_hit *inter)
{
	if (shape->type == SPHERE)
		return (sphere_intersect(&shape->data.sp, ray, inter));
	else if (shape->type == PLANE)
		return (plane_intersect(&shape->data.pl, ray, inter));
	else if (shape->type == CYLINDER)
		return (cylinder_intersect(&shape->data.cy, ray, inter));
	return (false);
}

bool	world_hit(t_vector *shapes, t_ray *ray, t_hit *closest)
{
	uint32_t		i;
	t_shape			*shape;
	t_hit	tmp;

	i = -1;
	tmp.t = INFINITY;
	tmp.shape = NULL;
	while(++i < shapes->size)
	{
		shape = nc_vector_at(shapes, i);
		if (!intersects(shape, ray, &tmp) || tmp.t >= closest->t)
			continue;
		*closest = tmp;
		closest->ray = *ray;
		closest->shape = shape;
		closest->point = ray_at(ray, closest->t);
		closest->normal = vec3_normalize(shape_normal(closest, ray));
	}
	return (closest->shape != NULL);
}

bool	reflected(t_light *light, t_hit *closest)
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

int	render(t_world *w)
{	
	t_vec3	coords;
	t_vec3	factors;
	t_ray	ray;
	t_hit	closest;
		
	coords.y = -1;
	while (++coords.y < HEIGHT)
	{
		coords.x = -1;
		while (++coords.x < WIDTH)
		{
			closest.color = BLACK;
			closest.shape = NULL;
			closest.t = INFINITY;
			factors = pixels_to_viewport(coords.x, coords.y); 	// Convert pixels to viewport coords (V point)
			ray = make_ray(w, factors);					// Make a ray from camera to V
			if (world_hit(w->shapes, &ray, &closest))
				closest.color = calculate_local_illumination(nc_vector_at(w->lights, 0), &closest, &w->ambient);	
			put_pixel(w, closest.color, coords.x, coords.y);
		}
	}
	mlx_put_image_to_window(w->disp.mlx, w->disp.win, w->disp.img, 0, 0);
	return (0);
}
