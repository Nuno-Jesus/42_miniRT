/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:30:28 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/08/09 20:09:27 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	message(t_world *world, char *text)
{
	destroy_world(&world);
	printf("Error\n%s\n", text);
	exit(EXIT_FAILURE);
}
