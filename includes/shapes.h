/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/13 16:25:41 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "miniRT.h"

t_plane		plane_new(char **point, char **normal, char **color);

void		plane_print(t_plane *p);

t_sphere	sphere_new(char **center, char *radius, char **color);

void		sphere_print(t_sphere *s);

t_cylinder	cylinder_new(char **tokens);

void		cylinder_print(t_cylinder *c);

t_shape		*shape_new(void	*data, t_shape_type type);

t_shape		*shape_copy(t_shape *shape);

void		shape_print(t_shape *shape);

#endif
