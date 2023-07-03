/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:10:38 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/03 17:21:06 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "miniRT.h"

t_plane	*plane_new(char **point, char **normal, char **color);

void	plane_debug(t_plane *p);
// t_sphere	*sphere_new(char **point, char **normal, char **color);
// t_cylinder	*cylinder_new(char **point, char **normal, char **color);

#endif
