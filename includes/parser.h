/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:19:03 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/04 16:11:43 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "miniRT.h"

/**
 * @brief Responsible for creating the t_world struct, enforce a couple
 * rules and call the parse_map function
 * 
 * @param filename The file to parse
 * @return t_world* The t_world struct with all entities information
 * @return NULL in case of error, like file misformatting
 */
t_world	*parse(char *filename);

/**
 * @brief Given the first token in a line, multiplexes the token
 * to redirect the program flow into the correct parsing function
 * 
 * @param world The t_world struct 
 * @param tokens The line tokens
 * @param counters An array with counters for the number of ambient
 * and camera entities
 * @return true If it is a valid entity 
 * @return false Otherwise
 */
bool	identifying(t_world *world, char **tokens, int counters[2]);

/**
 * @brief Parses the previously read map, by breaking each line into
 * its individual tokens.
 * 
 * @param world The t_world struct
 * @param map A matrix representing a map
 * @param counters An array with counters for the number of ambient 
 * and camera entities
 */
void	parse_map(t_world *world, char **map, int counters[2]);

/**
 * @brief Responsible for analyzing all the fields contained in the 
 * tokens variable, which represents the ambient light parameters.
 * If all goes fine, the ambient variable is filled with those parameters
 * (mostly converted to doubles and t_vec3 structures)
 * 
 * @param ambient The structure representing the ambient light
 * @param tokens The line fields
 * @param counter Part of an array with counters for the number of ambient 
 * and camera entities
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	parse_ambient_light(t_light *ambient, char **tokens, int *counter);

/**
 * @brief Responsible for analyzing all the fields contained in the 
 * tokens variable, which represents the camera parameters.
 * If all goes fine, the cam variable is filled with those parameters
 * (mostly converted to doubles and t_vec3 structures)
 * 
 * @param cam The structure representing the camera
 * @param tokens The line fields
 * @param counter Part of an array with counters for the number of ambient
 * and camera entities
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	parse_camera(t_camera *cam, char **tokens, int *counter);

/**
 * @brief Responsible for analyzing all the fields contained in the 
 * tokens variable, which represents the parameters of a light source.
 * If all goes fine, the lights vector is appended with a new t_light *
 * with those parameters (mostly converted to doubles and 
 * t_vec3 structures)
 * 
 * @param lights The lights vector (contains t_light pointers)
 * @param tokens The line fields
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	parse_light_source(t_vector *lights, char **tokens);

/**
 * @brief Responsible for analyzing all the fields contained in the 
 * tokens variable, which represents the parameters of a plane.
 * If all goes fine, the shapes vector is appended with a new t_shape *
 * with a t_plane with those parameters (mostly converted to doubles and
 * t_vec3 structures)
 * 
 * @param shapes The shapes vector (contains t_shapes pointers)
 * @param tokens The line fields
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	parse_plane(t_vector *shapes, char **tokens);

/**
 * @brief Responsible for analyzing all the fields contained in the 
 * tokens variable, which represents the parameters of a sphere.
 * If all goes fine, the shapes vector is appended with a new t_shape *
 * with a t_sphere with those parameters (mostly converted to doubles and
 * t_vec3 structures)
 * 
 * @param shapes The shapes vector (contains t_shapes pointers)
 * @param tokens The line fields
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	parse_sphere(t_vector *shapes, char **tokens);

/**
 * @brief Responsible for analyzing all the fields contained in the 
 * tokens variable, which represents the parameters of a cylinder.
 * If all goes fine, the shapes vector is appended with a new t_shape *
 * with a t_cylinder with those parameters (mostly converted to doubles and
 * t_vec3 structures)
 * 
 * @param shapes The shapes vector (contains t_shapes pointers)
 * @param tokens The line fields
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	parse_cylinder(t_vector *shapes, char **tokens);

/**
 * @brief Responsible for analyzing all the fields contained in the 
 * tokens variable, which represents the parameters of a textured plane.
 * If all goes fine, the shapes vector is appended with a new t_shape *
 * with a t_plane with those parameters (mostly converted to doubles and
 * t_vec3 structures). A flag is made active to later texturize the plane
 * 
 * @param shapes The shapes vector (contains t_shapes pointers)
 * @param tokens The line fields
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	parse_texture(t_vector *shapes, char **tokens);

/**
 * @brief Responsible for analyzing all the fields contained in the 
 * tokens variable, which represents the parameters of a cone.
 * If all goes fine, the lights vector is appended with a new t_shape *
 * with a t_cone with those parameters (mostly converted to doubles and
 * t_vec3 structures)
 * 
 * @param shapes The shapes vector (contains t_shapes pointers)
 * @param tokens The line fields
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	parse_cone(t_vector *shapes, char **tokens);

/**
 * @brief Checks if a double is well written. A well-written double is
 * considered to follow the following REGEX...
 * 
 * 			[0-9]+(.[0-9]+)?
 * 
 * ...which means it might have a fractional part or not (including the dot).
 * Every character must be a digit, except for the dot if present (which MUST
 * be followed by at least a number)
 * @param nb The tokens that describe some numbers
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	parse_double(char **nb);

/**
 * @brief Checks if a colors is well written. A well-written color is 
 * considered to be a color with RGB fields, divided by commas, with values
 * ranging from 0-255. Each field MUST be a number. No extra commas, or letters
 * are allowed.
 * 
 * @param color The tokens that describe a color
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	parse_rgb(char *color);

/**
 * @brief Given a list of tokens, if the token is meant to have commas, it must
 * have the exact number of it. Otherwise it must not have any. Besides, this 
 * function still calls the parse_double function to parse the values 
 * themselves.
 * 
 * To know which tokens must have commas or not, we hardcoded a binary string
 * that in each position k confirms that the token k must have commas (if the
 * value is set to 1)
 * 
 * @param tokens The tokens to parse 
 * @param code The code which identifies which tokens must have commas
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	parse_syntax(char **tokens, char *code);

/**
 * @brief Reads the map file. This function will skip both commented lines
 * (start with a #) and blank lines.
 * 
 * @param world The t_world struct
 * @param filename The file's name
 * @return char** A matrix containing the entire file
 * @return NULL If errors are found
 */
char	**read_map(t_world *world, char *filename);

/**
 * @brief Checks if the file's name is in accordance with the subject rules
 * 
 * @param filename The file's name 
 * @return true If no errors are found
 * @return false Otherwise
 */
bool	is_filename_valid(char *filename);

#endif
