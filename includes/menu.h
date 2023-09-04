/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:29:06 by maricard          #+#    #+#             */
/*   Updated: 2023/09/04 15:25:41 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_H
# define MENU_H

# include "miniRT.h"

//! Main menu Handlers
/**
 * @brief Handler for when the menu is close
 *
 * @param keycode The clicked key
 * @param w The world struct
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_closed_menu(int keycode, t_world *w);

/**
 * @brief Handler for when the menu is opened
 *
 * @param keycode The clicked key
 * @param w The world struct
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_opened_menu(int keycode, t_world *w);

/**
 * @brief Displays info of the menu
 *
 * @param w The world struct
 */
void			display_main_menu(t_world *w);

/**
 * @brief Displays the menu title UI
 *
 * @param w The world struct
 */
void			display_menu_title(t_world *w);

//! Shapes
/**
 * @brief Displays how many shapes and objects are in the scene
 *
 * @param w The world struct
 */
void			display_menu_entites(t_world *w);

/**
 * @brief Searches if there are shapes in the scene
 *
 * @param w The world struct
 */
void			search_shapes(t_world *w);

/**
 * @brief Checks if there are spheres in the scene
 *
 * @param w The world struct
 */
void			search_for_spheres(t_world *w);

/**
 * @brief Checks if there are planes in the scene
 *
 * @param w The world struct
 */
void			search_for_planes(t_world *w);

/**
 * @brief Checks if there are cylinders in the scene
 *
 * @param w The world struct
 */
void			search_for_cylinders(t_world *w);

/**
 * @brief Checks if there are cones in the scene
 *
 * @param w The world struct
 */
void			search_for_cones(t_world *w);

//! Camera
/**
 * @brief Handler for changes in the camera
 *
 * @param keycode The clicked key
 * @param w The world struct
 */
t_menu_state	handle_camera_changes(int keycode, t_world *w);

/**
 * @brief Displays the camera info
 *
 * @param w The world struct
 */
void			display_camera_menu(t_world *w);

//! Ambient light
/**
 * @brief Handler for changes in the ambient light
 *
 * @param keycode The clicked key
 * @param w The world struct
 */
t_menu_state	handle_amb_light_changes(int keycode, t_world *w);

/**
 * @brief Displays the ambient light info
 *
 * @param w The world struct
 */
void			display_amb_light_menu(t_world *w);

//! Light
/**
 * @brief Handler for changes in the light
 *
 * @param keycode The clicked key
 * @param w The world struct
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_light_changes(int keycode, t_world *w);

/**
 * @brief Handler for color related changes in lights
 *
 * @param keycode The clicked key
 * @param w The t_world struct
 * @param l The t_light struct
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_light_color_changes(int keycode, t_world *w, t_light *l);

/**
 * @brief checks if a light was selected
 *
 * @param keycode The clicked key
 * @param w The world struct
 */
t_menu_state	handle_light_choice(int keycode, t_world *w);

/**
 * @brief Displays all the available lights to control from the menu
 *
 * @param w The t_world struct
 * @param l The lights vector
 */
void			display_lights(t_world *w, t_vector *l);

/**
 * @brief Main menu for light info
 *
 * @param w The world struct
 * @param id The light id
 */
void			display_light_commands(t_world *w, int id);

/**
 * @brief Displays the light choice menu
 *
 * @param w The world struct
 */
void			display_light_choice_menu(t_world *w);

/**
 * @brief Displays the light info
 *
 * @param w The world struct
 */
void			display_light_info_1(t_world *w);

/**
 * @brief Displays the light info
 *
 * @param w The world struct
 */
void			display_light_info_2(t_world *w);

//! Sphere
/**
 * @brief Main menu for sphere info
 *
 * @param w The world struct
 * @param id The sphere id
 */
void			display_sphere_commands(t_world *w, int id);

/**
 * @brief Displays the sphere choice menu
 *
 * @param w The world struct
 */
void			display_sphere_choice_menu(t_world *w);

/**
 * @brief Handler for changes in the sphere
 *
 * @param keycode The clicked key
 * @param w The world struct
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_sphere_changes(int keycode, t_world *w);

/**
 * @brief Handler for size-related changes in spheres
 *
 * @param keycode The pressed key
 * @param w The t_world struct
 * @param sp The t_sphere struct to work with
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_sphere_size_change(int keycode, t_world *w,
					t_sphere *sp);

/**
 * @brief Handler for color-related changes in spheres
 *
 * @param keycode The pressed key
 * @param w The t_world struct
 * @param sp The t_sphere struct to work with
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_sphere_color_change(int keycode, t_world *w,
					t_sphere *sp);

/**
 * @brief checks if a sphere was selected
 *
 * @param keycode The clicked key
 * @param w The world struct
 */
t_menu_state	handle_sphere_choice(int keycode, t_world *w);

/**
 * @brief Displays the sphere info
 *
 * @param w The world struct
 */
void			display_sphere_info_1(t_world *w);

/**
 * @brief Displays the sphere info
 *
 * @param w The world struct
 */
void			display_sphere_info_2(t_world *w);

//! Plane
/**
 * @brief Main menu for plane info
 *
 * @param w The world struct
 * @param id The plane id
 */
void			display_plane_commands(t_world *w, int id);

/**
 * @brief Displays the plane choice menu
 *
 * @param w The world struct
 */
void			display_plane_choice_menu(t_world *w);

/**
 * @brief Displays the available planes to control from the menu
 *
 * @param w The t_world struct
 * @param shapes The shapes vector
 */
void			display_planes(t_world *w, t_vector *shapes);

/**
 * @brief Handler for changes in the plane
 *
 * @param keycode The clicked key
 * @param w The world struct
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_plane_changes(int keycode, t_world *w);

/**
 * @brief Handler for color-related changes in planes
 *
 * @param keycode The pressed key
 * @param w The t_world struct
 * @param pl The t_plane struct to work with
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_plane_color_changes(int keycode, t_world *w,
					t_plane *pl);

/**
 * @brief checks if a plane was selected
 *
 * @param keycode The clicked key
 * @param w The world struct
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_plane_choice(int keycode, t_world *w);

/**
 * @brief Displays the plane info
 *
 * @param w The world struct
 */
void			plane_info1(t_world *w);

/**
 * @brief Displays the plane info
 *
 * @param w The world struct
 */
void			plane_info2(t_world *w);

//! Cylinder
/**
 * @brief Main menu for cylinder info
 *
 * @param w The world struct
 * @param id The cylinder id
 */
void			display_cylinder_commands(t_world *w, int id);

/**
 * @brief Displays the cylinder choice menu
 *
 * @param w The world struct
 */
void			display_cylinder_choice_menu(t_world *w);

/**
 * @brief Displays the available cylinders to control from the menu
 *
 * @param w The t_world struct
 * @param shapes The shapes vector
 */
void			display_cylinder(t_world *w, t_vector *shapes);

/**
 * @brief Handler for changes in the cylinder
 *
 * @param keycode The clicked key
 * @param w The world struct
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_cylinder_changes(int keycode, t_world *w);

/**
 * @brief Handler for size-related changes in cylinders
 *
 * @param keycode The pressed key
 * @param w The t_world struct
 * @param cy The t_cylinder struct to work with
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_cylinder_size_changes(int keycode, t_world *w,
					t_cylinder *cy);

/**
 * @brief Handler for color-related changes in cylinders
 *
 * @param keycode The pressed key
 * @param w The t_world struct
 * @param cy The t_cylinder struct to work with
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_cylinder_color_changes(int keycode, t_world *w,
					t_cylinder *cy);

/**
 * @brief checks if a cylinder was selected
 *
 * @param keycode The clicked key
 * @param w The world struct
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_cylinder_choice(int keycode, t_world *w);

/**
 * @brief Displays the cylinder info
 *
 * @param w The world struct
 */
void			display_cylinder_info_1(t_world *w);

/**
 * @brief Displays the cylinder info
 *
 * @param w The world struct
 */
void			display_cylinder_info_2(t_world *w);

//! Cone
/**
 * @brief Main menu for cone info
 *
 * @param w The world struct
 * @param id The cone id
 */
void			display_cone_commands(t_world *w, int id);

/**
 * @brief Displays the cone choice menu
 *
 * @param w The world struct
 */
void			display_cone_choice_menu(t_world *w);

/**
 * @brief Displays the available cones to control from the menu
 *
 * @param w The t_world struct
 * @param shapes The shapes vector
 */
void			display_cones(t_world *w, t_vector *shapes);

/**
 * @brief Handler for changes in the cone
 *
 * @param keycode The clicked key
 * @param w The world struct
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_cone_changes(int keycode, t_world *w);

/**
 * @brief Handler for size-related changes in cones
 *
 * @param keycode The pressed key
 * @param w The t_world struct
 * @param co The t_cone struct to work with
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_cone_size_changes(int keycode, t_world *w, t_cone *co);

/**
 * @brief Handler for color-related changes in cones
 *
 * @param keycode The pressed key
 * @param w The t_world struct
 * @param co The t_cone struct to work with
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_cone_color_changes(int keycode, t_world *w, t_cone *co);

/**
 * @brief checks if a cone was selected
 *
 * @param keycode The clicked key
 * @param w The world struct
 * @return t_menu_state The next menu state
 */
t_menu_state	handle_cone_choice(int keycode, t_world *w);

/**
 * @brief Displays the cone info
 *
 * @param w The world struct
 */
void			display_cone_info_1(t_world *w);

/**
 * @brief Displays the cone info
 *
 * @param w The world struct
 */
void			display_cone_info_2(t_world *w);

#endif
