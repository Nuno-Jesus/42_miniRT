/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:12:25 by maricard          #+#    #+#             */
/*   Updated: 2023/07/03 19:07:47 by ncarvalh         ###   ########.fr       */
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
		// unsigned int i;

		// i = 0;
		// while (i < root->spheres->size)
		// {
		// 	printf("--> LIGHT SOURCE DATA\n");
		// 	printf("root->source[%d].origin.x = %f\n", i, root->source[i].origin.x);
		// 	printf("root->source[%d].origin.y = %f\n", i, root->source[i].origin.y);
		// 	printf("root->source[%d].origin.z = %f\n", i, root->source[i].origin.z);
		// 	printf("root->source[%d].brightness = %f\n", i, root->source[i].brightness);
		// 	printf("root->source[%d].color.r = %d\n", i, root->source[i].color.r);
		// 	printf("root->source[%d].color.g = %d\n", i, root->source[i].color.g);
		// 	printf("root->source[%d].color.b = %d\n\n", i, root->source[i].color.b);
		// 	i++;
		// }
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

bool	parse_ambient_light(t_root *root, char **tokens)
{
	char 	**data;

	if (nc_matrix_size(tokens) != 3)
		return (false);
	if (!parse_syntax(tokens, "001"))
		return (false);
	root->ambient.ratio = ft_atof(tokens[1]);
	data = nc_split(tokens[2], ',');
	if (!check_rgb(data))
		message(root, "Wrong color syntax for ambient lightning");
	root->ambient.color.r = nc_atoi(data[0]);
	root->ambient.color.g = nc_atoi(data[1]);
	root->ambient.color.b = nc_atoi(data[2]);
	nc_matrix_delete(data, &free);
	return (true);
	//print_data(root, "ambient light");
}

bool	parse_camera(t_root *root, char **tokens)
{
	char	 **data;

	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0110"))
		return (false);
	data = nc_split(tokens[1], ',');
	root->camera.origin.x = ft_atof(data[0]);
	root->camera.origin.y = ft_atof(data[1]);
	root->camera.origin.z = ft_atof(data[2]);
	nc_matrix_delete(data, &free);
	data = nc_split(tokens[2], ',');
	root->camera.normal.x = ft_atof(data[0]);
	root->camera.normal.y = ft_atof(data[1]);
	root->camera.normal.z = ft_atof(data[2]);
	root->camera.fov = ft_atof(tokens[3]);
	nc_matrix_delete(data, &free);
	return (true);
	//print_data(root, "camera");
}

t_lightsource	*light_new(char **origin, char *brightness, char **color)
{
	t_lightsource	*light;

	light = nc_calloc(1, sizeof(t_lightsource));
	if (!light)
		return (NULL);
	*light = (t_lightsource)
	{
		.origin.x = ft_atof(origin[0]),
		.origin.y = ft_atof(origin[1]),
		.origin.z = ft_atof(origin[2]),
		.brightness = ft_atof(brightness),
		.color.r = nc_atoi(color[0]),
		.color.g = nc_atoi(color[1]),
		.color.b = nc_atoi(color[2])
	};
	return (light);
}

bool	parse_light_source(t_root *root, char **tokens)
{
	char 	**origin;
	char 	**color;
	t_lightsource	*light;	
	
	if (nc_matrix_size(tokens) != 4)
		return (false);
	if (!parse_syntax(tokens, "0101"))
		return (false);
	origin = nc_split(tokens[1], ',');
	color = nc_split(tokens[3], ',');
	light = light_new(origin, tokens[2], color);
	nc_vector_push(root->sources, light);
	if (!check_rgb(color))
		message(root, "Wrong color syntax for light source");
	nc_matrix_delete(origin, &free);
	nc_matrix_delete(color, &free);
	return (true);
	//print_data(root, "light source");
}

