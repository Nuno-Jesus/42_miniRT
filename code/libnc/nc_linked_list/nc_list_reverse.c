/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:36:03 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 16:36:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_list_reverse(t_list **begin_list)
{
	t_list	*curr;
	t_list	*aux;
	t_list	*list;

	if (!begin_list)
		return ;
	list = NULL;
	curr = *begin_list;
	while (curr)
	{
		aux = curr->next;
		curr->next = list;
		list = curr;
		curr = aux;
	}
	*begin_list = list;
}
