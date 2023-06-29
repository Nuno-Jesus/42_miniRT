/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 15:08:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 16:09:40 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "miniRT.h"

int main(void)
{
	//Print degrees to radians with 30 degrees
	printf("30 degrees in radians: %.3f\n", RADIANS(45));

	//Print radians to degrees with PI/2 radians
	printf("PI/2 radians in degrees: %.3f\n", DEGREES(PI/2));
	return (0);	
}