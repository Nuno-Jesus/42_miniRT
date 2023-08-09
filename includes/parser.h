/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:19:03 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 19:22:16 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "miniRT.h"

t_world	*parse(char *filename);

void	parse_map(t_world *root, char **map);

char	**read_map(t_world *root, char *filename);

bool	identifying(t_world *root, char **tokens);

bool	parse_syntax(char **tokens, char *code);

bool	is_filename_valid(char *filename);

bool	parse_ambient_light(t_world *root, char **tokens);

bool	parse_camera(t_world *root, char **tokens);

bool	parse_light_source(t_world *root, char **tokens);

bool	parse_plane(t_world *root, char **tokens);

bool	parse_sphere(t_world *root, char **tokens);

bool	parse_cylinder(t_world *root, char **tokens);

bool	parse_double(char **nb);

bool	parse_rgb(char *color);

#endif
