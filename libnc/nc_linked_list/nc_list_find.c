/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:35:40 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 16:35:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_list	*nc_list_find(t_list *begin_list, void *data_ref, int (*cmp)(void *, void *))
{
	if (!cmp)
		return (NULL);
	while (begin_list)
	{
		if (!(*cmp)(begin_list->content, data_ref))
			break ;
		begin_list = begin_list->next;
	}
	return (begin_list);
}
