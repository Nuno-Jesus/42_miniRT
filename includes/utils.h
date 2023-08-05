/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:04:41 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/05 16:46:06 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "miniRT.h"

void	message(t_root *root, char *text);

void	destroy_root(t_root **root);

double	determinant(t_equation *eq);

int		quadformula(t_equation *eq);

void	closest_point(double t, t_ray *ray, t_color *color);

#endif