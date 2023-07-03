/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/03 18:28:01 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "miniRT.h"

t_plane		*plane_new(char **point, char **normal, char **color);

t_plane		*plane_copy(t_plane *plane);

void		plane_print(t_plane *p);

t_sphere	*sphere_new(char **center, char *radius, char **color);

t_sphere	*sphere_copy(t_sphere *sphere);

void		sphere_print(t_sphere *s);

t_cylinder	*cylinder_new(char **center, char **normal, char *radius, char *height, char **color);

t_cylinder	*cylinder_copy(t_cylinder *cylinder);

void		cylinder_print(t_cylinder *c);

t_lightsource *source_new(char **point, char *ratio, char **color);

t_lightsource *source_copy(t_lightsource *lightsource);

void		source_print(t_lightsource *l);

#endif
