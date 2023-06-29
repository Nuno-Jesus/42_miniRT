/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:30:12 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 12:38:20 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int main(void)
{
	//Allocate a 10 position pointer
	int *a = malloc(sizeof(int) * 10);
	if (a[0])
		hello();
	free(a);
	return (0);
}