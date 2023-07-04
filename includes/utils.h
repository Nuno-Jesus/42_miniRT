/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:32:00 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/04 16:31:11 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "miniRT.h"

float	nc_atof(char *str);

void	message(t_root *root, char *text);

void	destroy_root(t_root **root);

int		nc_count(char *str, char c);

bool	parse_float(char **nb);

bool	parse_rgb(char **data);

#endif