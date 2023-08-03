/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:19:03 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/03 13:06:29 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "miniRT.h"

t_root	*parse(char *filename);

void	parse_map(t_root *root, char **map);

char	**read_map(t_root *root, char *filename);

bool	identifying(t_root *root, char **tokens);

bool	parse_syntax(char **tokens, char *code);

bool	is_filename_valid(char *filename);

bool	parse_ambient_light(t_root *root, char **tokens);

bool	parse_camera(t_root *root, char **tokens);

bool	parse_light_source(t_root *root, char **tokens);

bool	parse_plane(t_root *root, char **tokens);

bool	parse_sphere(t_root *root, char **tokens);

bool	parse_cylinder(t_root *root, char **tokens);

bool	parse_double(char **nb);

bool	parse_rgb(char *color);

#endif
