/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:35:53 by marvin            #+#    #+#             */
/*   Updated: 2023/07/03 15:40:17 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_list	*nc_list_map(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list2;
	t_list	*node;

	list2 = NULL;
	if (!list || !f)
		return (NULL);
	while (list != NULL)
	{
		node = nc_list_new(f(list->content));
		if (!node)
		{
			nc_list_clear(&list, del);
			return (NULL);
		}
		nc_list_add_back(&list2, node);
		list = list->next;
	}
	return (list2);
}
