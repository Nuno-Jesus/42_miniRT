/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   illumination.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:43:46 by maricard          #+#    #+#             */
/*   Updated: 2023/07/04 17:02:45 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ILLUMINATION_H
# define ILLUMINATION_H

# include "miniRT.h"

void			ambient_print(t_light *s);

void			camera_print(t_camera *s);

t_lightsource	*source_new(char **point, char *ratio, char **color);

t_lightsource	*source_copy(t_lightsource *lightsource);

void			source_print(t_lightsource *l);

#endif
