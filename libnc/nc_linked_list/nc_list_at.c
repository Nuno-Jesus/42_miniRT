/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:35:23 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 16:35:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_list	*nc_list_at(t_list *begin_list, unsigned int nbr)
{
	while (begin_list && nbr--)
		begin_list = begin_list->next;
	return (begin_list);
}
