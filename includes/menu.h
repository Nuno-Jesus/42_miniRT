/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:29:06 by maricard          #+#    #+#             */
/*   Updated: 2023/08/29 17:18:00 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# include "miniRT.h"

//! Handlers

t_menu_state	handle_closed_menu(int keycode, t_world *w);

// void	render_menu(t_world *w);

//! Menu
// void	main_menu(t_world *w);

t_menu_state	handle_opened_menu(int keycode, t_world *w);

void	display_main_menu(t_world *w);

void	display_menu_title(t_world *w);

//! Shapes
void	display_menu_entites(t_world *w);

void	init_flags(t_world *w);

void	search_shapes(t_world *w);

void	check_for_spheres(t_world *w);

void	check_for_planes(t_world *w);

void	check_for_cylinders(t_world *w);

void	check_for_cones(t_world *w);

//! Camera
void	display_camera_menu(t_world *w);

t_menu_state	handle_camera_changes(int keycode, t_world *w);

//! Ambient light
void	display_amb_light_menu(t_world *w);

t_menu_state	handle_amb_light_changes(int keycode, t_world *w);

//! Light

t_menu_state	handle_light_changes(int keycode, t_world *w);

t_menu_state	handle_light_choice(int keycode, t_world *w);

void	display_light_commands(t_world *w, int id);

void	display_light_choice_menu(t_world *w);

void	light_info1(t_world *w);

void	light_info2(t_world *w);

void	light_info3(t_world *w);

//! Sphere
void	sphere(t_world *w, int id);

void	handle_sphere_choice(t_world *w);

int		move_sphere(int keycode, t_world *w);

void	sphere_info1(t_world *w);

void	sphere_info2(t_world *w);

void	sphere_info3(t_world *w);

//! Plane
void	plane(t_world *w, int id);

void	handle_plane_choice(t_world *w);

int		move_plane(int keycode, t_world *w);

void	plane_info1(t_world *w);

void	plane_info2(t_world *w);

//! Cylinder
void	cylinder(t_world *w, int id);

void	handle_cylinder_choice(t_world *w);

int		move_cylinder(int keycode, t_world *w);

void	cylinder_info1(t_world *w);

void	cylinder_info2(t_world *w);

void	cylinder_info3(t_world *w);

//! Cone
void	cone(t_world *w, int id);

void	handle_cone_choice(t_world *w);

int		move_cone(int keycode, t_world *w);

void	cone_info1(t_world *w);

void	cone_info2(t_world *w);

void	cone_info3(t_world *w);

#endif