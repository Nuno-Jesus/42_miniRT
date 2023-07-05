/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:01:11 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/05 11:23:52 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "macros.h"
# include "get_next_line.h"
# include "libnc.h"
# include "vector.h"
# include "structs.h"
# include "parser.h"
# include "utils.h"
# include "shapes.h"
# include "illumination.h"

t_color	color_new(int r, int g, int b);

#endif