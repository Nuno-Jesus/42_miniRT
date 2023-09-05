/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_list_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:35:36 by marvin            #+#    #+#             */
/*   Updated: 2023/07/03 15:39:56 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_list_delone(t_list *list, void (*del)(void *))
{
	if (!list)
		return ;
	if (del)
		(*del)(list->content);
	free(list);
}
