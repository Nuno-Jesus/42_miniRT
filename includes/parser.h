/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:19:03 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/15 15:35:26 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "miniRT.h"

t_world	*parse(char *filename);

bool	identifying(t_world *world, char **tokens, int count[3]);

void	parse_map(t_world *world, char **map, int counters[3]);

bool	parse_ambient_light(t_light *ambient, char **tokens, int counters[3]);

bool	parse_camera(t_camera *cam, char **tokens, int counters[3]);

bool	parse_light_source(t_vector *lights, char **tokens, int counters[3]);

bool	parse_plane(t_vector *shapes, char **tokens);

bool	parse_sphere(t_vector *shapes, char **tokens);

bool	parse_cylinder(t_vector *shapes, char **tokens);

bool	parse_torus(t_vector *shapes, char **tokens);

bool	parse_double(char **nb);

bool	parse_rgb(char *color);

bool	parse_syntax(char **tokens, char *code);

char	**read_map(t_world *world, char *filename);

bool	is_filename_valid(char *filename);
#endif
