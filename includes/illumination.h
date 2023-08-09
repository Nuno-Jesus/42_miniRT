/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:43:46 by maricard          #+#    #+#             */
/*   Updated: 2023/08/09 19:10:03 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILLUMINATION_H
# define ILLUMINATION_H

# include "miniRT.h"

void			ambient_print(t_light *s);

void			camera_print(t_camera *s);

t_light	*source_new(char **point, char *ratio, char **color);

t_light	*source_copy(t_light *lightsource);

void			source_print(t_light *l);

#endif
