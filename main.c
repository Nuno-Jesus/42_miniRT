/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 17:29:22 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int argc, char **argv)
{
	(void)argc;
	t_root	*root;
	
	if (argc != 2)
		message(NULL, "Usage: ./miniRT <scene>.rt");
	root = parse(argv[1]);
	destroy_root(&root);
	return (0);		
}