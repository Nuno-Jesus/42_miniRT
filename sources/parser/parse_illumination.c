/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:12:25 by maricard          #+#    #+#             */
/*   Updated: 2023/07/03 17:49:22 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_data(t_root *root, char *type)
{
	if (!strcmp(type, "ambient light"))
	{
		printf("\n--> AMBIENT LIGHT DATA\n");
		printf("root->ambient.ratio = %f\n", root->ambient.ratio);
		printf("root->ambient.color.r = %d\n", root->ambient.color.r);
		printf("root->ambient.color.g = %d\n", root->ambient.color.g);
		printf("root->ambient.color.b = %d\n\n", root->ambient.color.b);
	}
	else if (!strcmp(type, "camera"))
	{
		printf("\n--> CAMERA DATA\n");
		printf("root->camera.origin.x = %f\n", root->camera.origin.x);
		printf("root->camera.origin.y = %f\n", root->camera.origin.y);
		printf("root->camera.origin.z = %f\n", root->camera.origin.z);
		printf("root->camera.normal.x = %f\n", root->camera.normal.x);
		printf("root->camera.normal.y = %f\n", root->camera.normal.y);
		printf("root->camera.normal.z = %f\n", root->camera.normal.z);
		printf("root->camera.fov = %f\n\n", root->camera.fov);
	}
	else if (!strcmp(type, "light source"))
	{
		int i = 0;
		while (i < root->num_sources)
		{
			printf("--> LIGHT SOURCE DATA\n");
			printf("root->source[%d].origin.x = %f\n", i, root->source[i].origin.x);
			printf("root->source[%d].origin.y = %f\n", i, root->source[i].origin.y);
			printf("root->source[%d].origin.z = %f\n", i, root->source[i].origin.z);
			printf("root->source[%d].brightness = %f\n", i, root->source[i].brightness);
			printf("root->source[%d].color.r = %d\n", i, root->source[i].color.r);
			printf("root->source[%d].color.g = %d\n", i, root->source[i].color.g);
			printf("root->source[%d].color.b = %d\n\n", i, root->source[i].color.b);
			i++;
		}
	}
}

bool	check_rgb(char **data)
{
	int i;
	int a;

	i = 0;
	while (data[i])
	{
		a = 0;
		while (data[i][a] && data[i][a] != '\n')
		{
			if (!nc_isdigit(data[i][a]))
			{
				nc_matrix_delete(data, &free);
				return (false);
			}
			a++;
		}
		if (nc_atoi(data[i]) < 0 || nc_atoi(data[i]) > 255)
		{
			nc_matrix_delete(data, &free);
			return (false);
		}
		i++;
	}
	return (true);
}

void	parse_ambient_light(t_root *root, char **tokens)
{
	char 	**data;

	if (nc_matrix_size(tokens) != 3)
		message(root, "Wrong number of arguments for ambient light");
	if (!parse_syntax(tokens, "001"))
		message(root, "Wrong syntax for ambient light");
	root->ambient.ratio = ft_atof(tokens[1]);
	data = nc_split(tokens[2], ',');
	if (!check_rgb(data))
		message(root, "Wrong color syntax for ambient lightning");
	root->ambient.color.r = nc_atoi(data[0]);
	root->ambient.color.g =  nc_atoi(data[1]);
	root->ambient.color.b = nc_atoi(data[2]);
	//print_data(root, "ambient light");
}

void	parse_camera(t_root *root, char **tokens)
{
	char	 **data;

	if (nc_matrix_size(tokens) != 4)
		message(root, "Wrong number of arguments for camera");
	if (!parse_syntax(tokens, "0110"))
		message(root, "Wrong syntax for camera");
	data = nc_split(tokens[1], ',');
	root->camera.origin.x = ft_atof(data[0]);
	root->camera.origin.y = ft_atof(data[1]);
	root->camera.origin.z = ft_atof(data[2]);
	data = nc_split(tokens[2], ',');
	root->camera.normal.x = ft_atof(data[0]);
	root->camera.normal.y = ft_atof(data[1]);
	root->camera.normal.z = ft_atof(data[2]);
	root->camera.fov = ft_atof(tokens[3]);
	//print_data(root, "camera");
}

static void print(char **mat, size_t i)
{
	//Print element i
	printf("mat[%zu] = %s\n", i, mat[i]);
}

void	parse_light_source(t_root *root, char **tokens)
{
	char 	**data;
	int 	k;
	
	if (nc_matrix_size(tokens) != 4)
		message(root, "Wrong number of arguments for light source");
	if (!parse_syntax(tokens, "0101"))
		message(root, "Wrong syntax for light source");
	root->num_sources++;
	k = root->num_sources - 1;
	if (k == 0)
		root->source = nc_matrix_new(1, sizeof(t_lightsource));
	else
		root->source = nc_matrix_append(root->source, NULL, (void *)&nc_strdup);
	data = nc_split(tokens[1], ',');
	root->source[k].origin.x = ft_atof(data[0]);
	root->source[k].origin.y = ft_atof(data[1]);
	root->source[k].origin.z = ft_atof(data[2]);
	root->source[k].brightness = ft_atof(tokens[2]);
	data = nc_split(tokens[3], ',');
	if (!check_rgb(data))
		message(root, "Wrong color syntax for light source");
	root->source[k].color.r = nc_atoi(data[0]);
	root->source[k].color.g = nc_atoi(data[1]);
	root->source[k].color.b = nc_atoi(data[2]);
	//print_data(root, "light source");
}
