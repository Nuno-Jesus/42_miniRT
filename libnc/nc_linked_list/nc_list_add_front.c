/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_list_add_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:35:19 by marvin            #+#    #+#             */
/*   Updated: 2023/06/29 19:50:06 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_list_add_front(t_list **list, t_list *new)
{
	if (!new || !list)
		return ;
	if (!(*list))
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
}
