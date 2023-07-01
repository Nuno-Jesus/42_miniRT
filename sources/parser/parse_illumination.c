/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:12:25 by maricard          #+#    #+#             */
/*   Updated: 2023/07/01 16:50:14 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_ambient_light(t_root *root, char **tokens)
{
	char 	**data;
	int 	i;
	
	i = -1;
	if (nc_matrix_size(tokens) != 4)
		message(root, "Wrong number of arguments for ambient light");
	if (!parse_syntax(tokens, "001"))
		message(root, "Wrong syntax for ambient light");
	while (tokens[++i])
		data = nc_split(tokens[i], ',');
	root->ambient.ratio = ft_atof(data[0]);
	root->ambient.color.r = ft_atof(data[1]);
	root->ambient.color.g =  ft_atof(data[2]);
	root->ambient.color.b = ft_atof(data[3]);
	printf("nc_matrix_size(tokens) = %zu\n", nc_matrix_size(tokens));
	printf("root->ambient.ratio = %f\n", root->ambient.ratio);
	printf("root->ambient.color.r = %d\n", root->ambient.color.r);
	printf("root->ambient.color.g = %d\n", root->ambient.color.g);
	printf("root->ambient.color.b = %d\n", root->ambient.color.b);
	(void) root;
	(void) tokens;
}

void	parse_camera(t_root *root, char **tokens)
{
	char	 **data;
	int 	i;
	
	i = -1;
	if (nc_matrix_size(tokens) != 7)
		message(root, "Wrong number of arguments for camera");
	if (!parse_syntax(tokens, "0110"))
		message(root, "Wrong syntax for camera");
	while (tokens[++i])
		data = nc_split(tokens[i], ',');
	root->camera.origin.x = ft_atof(data[0]);
	root->camera.origin.y = ft_atof(data[1]);
	root->camera.origin.z = ft_atof(data[2]);
	root->camera.normal.x = ft_atof(data[3]);
	root->camera.normal.y = ft_atof(data[4]);
	root->camera.normal.z = ft_atof(data[5]);
	root->camera.fov = ft_atof(data[6]);
	printf("nc_matrix_size(tokens) = %zu\n", nc_matrix_size(tokens));
	printf("root->camera.origin.x = %f\n", root->camera.origin.x);
	printf("root->camera.origin.y = %f\n", root->camera.origin.y);
	printf("root->camera.origin.z = %f\n", root->camera.origin.z);
	printf("root->camera.normal.x = %f\n", root->camera.normal.x);
	printf("root->camera.normal.y = %f\n", root->camera.normal.y);
	printf("root->camera.normal.z = %f\n", root->camera.normal.z);
	printf("root->camera.fov = %f\n", root->camera.fov);
	(void) root;
	(void) tokens;
}

void	parse_light_source(t_root *root, char **tokens)
{
	char 	**data;
	int 	i;
	int 	k;
	
	i = -1;
	if (nc_matrix_size(tokens) != 7)
		message(root, "Wrong number of arguments for light source");
	if (!parse_syntax(tokens, "0101"))
		message(root, "Wrong syntax for light source");
	while (tokens[++i])
		data = nc_split(tokens[i], ',');
	k = root->num_sources;
	root->source[k].origin.x = ft_atof(data[0]);
	root->source[k].origin.y = ft_atof(data[1]);
	root->source[k].origin.z = ft_atof(data[2]);
	root->source[k].brightness = ft_atof(data[3]);
	root->source[k].color.r = ft_atof(data[4]);
	root->source[k].color.g = ft_atof(data[5]);
	root->source[k].color.b = ft_atof(data[6]);
	printf("nc_matrix_size(tokens) = %zu\n", nc_matrix_size(tokens));
	printf("root->source[k].origin.x = %f\n", root->source[k].origin.x);
	printf("root->source[k].origin.y = %f\n", root->source[k].origin.y);
	printf("root->source[k].origin.z = %f\n", root->source[k].origin.z);
	printf("root->source[k].brightness = %f\n", root->source[k].brightness);
	printf("root->source[k].color.r = %d\n", root->source[k].color.r);
	printf("root->source[k].color.g = %d\n", root->source[k].color.g);
	printf("root->source[k].color.b = %d\n", root->source[k].color.b);
	root->num_sources++;
	(void) root;
	(void) tokens;
}
