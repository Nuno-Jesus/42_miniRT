/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:05:45 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 15:05:44 by maricard         ###   ########.fr       */
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
	ray.direction = vec3_normalize(vec3_sub(res, ray.origin));
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
		inter->ray = *ray;
		inter->shape = shape;
		inter->point = ray_at(ray, inter->t);
		inter->normal = vec3_normalize(normal(inter, ray));
	}
	return (hit);
}

bool	world_hit(t_vector *shapes, t_ray *ray, t_inter *closest)
{
	t_shape		*shape;
	t_inter		tmp;
	uint32_t	i;

	i = -1;
	nc_bzero(&tmp, sizeof(t_inter));
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

bool	reflected(t_lightsource *light, t_inter *closest)
{
	t_vec3 reflection;
	t_vec3 light_dir;
	double cossine;

	//2 * (N ⋅ L) * N - L
	light_dir = vec3_sub(light->origin, closest->point);
	reflection = vec3_scale(closest->normal, 2 * vec3_dot(closest->normal, light_dir));
	reflection = vec3_sub(reflection, light_dir);
	reflection = vec3_normalize(reflection);
	cossine = vec3_cos(light_dir, reflection);
	double angle;

	angle = DEGREES(acos(cossine));
	if (angle >= 0.0 - EPSILON && angle <= 180.0 + EPSILON)
	{
		// printf("Angle: %f\n", angle);
		return (true);
	}
	return (false);
}

t_color	calculate_global_illumination(t_lightsource *bulb, t_inter *closest, t_light *amb_light)
{
	t_color	color;

	(void)bulb;
	color = ambient(closest->color, amb_light->ratio);
	//if (reflected(bulb, closest))
	color = color_add(color, diffuse(bulb, closest, KDIFFUSE));
	return (color);
}

int	render(t_root *r)
{	
	t_vec3	coords;
	t_vec3	factors;
	t_ray	ray;
	t_inter	closest;
	t_color color;
	
	coords.y = -1;
	while (++coords.y < HEIGHT)
	{
		coords.x = -1;
		while (++coords.x < WIDTH)
		{
			color = BLACK;
			nc_bzero(&closest, sizeof(t_inter));
			factors = world_to_viewport(coords.x, coords.y); 	// Convert pixels to viewport coords (V point)
			ray = make_ray(r, factors);					// Make a ray from camera to V
			if (world_hit(r->shapes, &ray, &closest))
				color = calculate_global_illumination(nc_vector_at(r->sources, 0), &closest, &r->ambient);	
			put_pixel(r, color, coords.x, coords.y);
		}
	}
	mlx_put_image_to_window(r->disp.mlx, r->disp.win, r->disp.img, 0, 0);
	return (0);
}
