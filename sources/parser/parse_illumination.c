/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:12:35 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/30 16:43:34 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_ambient_light(t_root *root, char **tokens)
{
	char 	**data;

	// ! check number of args
	if (!parse_syntax(tokens, "001"))
		message(root, "Wrong syntax for ambient light");
	data = nc_split(tokens, ',');
	root->ambient.ratio = nc_atof(data[0]);
	root->ambient.color.r = data[1];
	root->ambient.color.g = data[2];
	root->ambient.color.b = data[3];
	(void) root;
	(void) tokens;
}

void	parse_camera(t_root *root, char **tokens)
{
	char **data;
	
	// ! check number of args
	if (!parse_syntax(tokens, "0110"))
		message(root, "Wrong syntax for camera");
	data = nc_split(tokens, ',');
	root->camera.origin.x = nc_atof(data[0]);
	root->camera.origin.y = nc_atof(data[1]);
	root->camera.origin.z = nc_atof(data[2]);
	root->camera.normal.x = nc_atof(data[3]);
	root->camera.normal.y = nc_atof(data[4]);
	root->camera.normal.z = nc_atof(data[5]);
	root->camera.fov = nc_atof(data[6]);
	(void) root;
	(void) tokens;
}

void	parse_light_source(t_root *root, char **tokens)
{
	char 	**data;
	int 	k;
	
	// ! check number of args
	if (!parse_syntax(tokens, "0101"))
		message(root, "Wrong syntax for light source");
	data = nc_split(tokens, ',');
	k = root->num_sources;
	root->source[k].origin.x = nc_atof(data[0]);
	root->source[k].origin.y = nc_atof(data[1]);
	root->source[k].origin.z = nc_atof(data[2]);
	root->source[k].brightness = nc_atof(data[3]);
	root->source[k].color.r = nc_atof(data[4]);
	root->source[k].color.g = nc_atof(data[5]);
	root->source[k].color.b = nc_atof(data[6]);
	root->num_sources++;
	(void) root;
	(void) tokens;
}
