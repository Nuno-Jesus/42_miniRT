/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:29:06 by maricard          #+#    #+#             */
/*   Updated: 2023/08/23 20:05:32 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# include "miniRT.h"

//! Menu
void	main_menu(t_world *w);

void	render_menu(t_world *w);

int		menu_keys(int keycode, t_world *w);

void	menu_execution(t_world *w);

void	menu_text(t_world *w);

//! Shapes
void	write_shapes(t_world *w);

void	init_flags(t_world *w);

void	search_shapes(t_world *w);

void	check_for_spheres(t_world *w);

void	check_for_planes(t_world *w);

void	check_for_cylinders(t_world *w);

void	check_for_cones(t_world *w);

//! Camera
void	change_camera(t_world *w);

//! Ambient light
void	change_ambient_light(t_world *w);

//! Light
int		light_menu(int keycode, t_world *w);

int		move_light(int keycode, t_world *w);

void	light(t_world *w, int id);

void	change_light(t_world *w);

void	light_info1(t_world *w);

void	light_info2(t_world *w);

void	light_info3(t_world *w);

//! Sphere
void	sphere(t_world *w, int id);

void	change_sphere(t_world *w);

int		move_sphere(int keycode, t_world *w);

void	sphere_info1(t_world *w);

void	sphere_info2(t_world *w);

void	sphere_info3(t_world *w);

//! Plane
void	plane(t_world *w, int id);

void	change_plane(t_world *w);

int		move_plane(int keycode, t_world *w);

void	plane_info1(t_world *w);

void	plane_info2(t_world *w);

//! Cylinder
void	cylinder(t_world *w, int id);

void	change_cylinder(t_world *w);

int		move_cylinder(int keycode, t_world *w);

void	cylinder_info1(t_world *w);

void	cylinder_info2(t_world *w);

void	cylinder_info3(t_world *w);

//! Cone
void	cone(t_world *w, int id);

void	change_cone(t_world *w);

int		move_cone(int keycode, t_world *w);

void	cone_info1(t_world *w);

void	cone_info2(t_world *w);

void	cone_info3(t_world *w);

#endif