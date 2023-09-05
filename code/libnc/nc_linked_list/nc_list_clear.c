/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:35:32 by marvin            #+#    #+#             */
/*   Updated: 2023/07/03 15:39:33 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_list_clear(t_list **list, void (*del)(void *))
{
	t_list	*curr;

	if (!list || !(*list))
		return ;
	while (*list != NULL)
	{
		curr = *list;
		*list = (*list)->next;
		nc_list_delone(curr, del);
	}
}
