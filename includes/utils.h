/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:32:00 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/03 20:12:05 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "miniRT.h"

float	ft_atof(char *str);

void	message(t_root *root, char *text);

void	destroy_root(t_root **root);

int		nc_count(char *str, char c);

bool	parse_float(char **nb);

bool	parse_rgb(char **data);

#endif