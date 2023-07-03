/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maricard <maricard@student.porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:20:25 by maricard          #+#    #+#             */
/*   Updated: 2023/07/03 20:14:28 by maricard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ambient_print(t_light *s)
{
	printf("Ambient:\n");
	printf("  Ratio: (%02.f)\n", s->ratio);
	printf("  Color: (%d, %d, %d)\n", s->color.r, s->color.g, s->color.b);
}
