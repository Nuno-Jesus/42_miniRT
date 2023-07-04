/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:30:28 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/04 17:18:35 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	message(t_root *root, char *text)
{
	destroy_root(&root);
	printf("Error\n%s\n", text);
	exit(EXIT_FAILURE);
}
