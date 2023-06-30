/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:11:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/30 16:33:38 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	parse_plane(t_root *root, char **tokens)
{
	// parse_syntax(tokens, "0111");
	(void) root;
	(void) tokens;
}

void	parse_sphere(t_root *root, char **tokens)
{
	parse_syntax(tokens, "0101");
	(void) root;
}

void	parse_cylinder(t_root *root, char **tokens)
{
	// parse_syntax(tokens, "011001");
	(void) root;
	(void) tokens;
}