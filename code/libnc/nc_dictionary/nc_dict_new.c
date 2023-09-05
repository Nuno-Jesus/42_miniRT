/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dict_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:33:02 by marvin            #+#    #+#             */
/*   Updated: 2023/05/14 16:33:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

t_dict	*nc_dict_new(int (*cmp)(void *, void *), void *(*cpy)(void *), \
	void (*del)(void *), char *(*str)(void *))
{
	t_dict	*dict;

	dict = nc_calloc(1, sizeof(t_dict));
	if (!dict)
		return (NULL);
	dict->keycmp = cmp;
	dict->keycpy = cpy;
	dict->keydel = del;
	dict->keystr = str;
	return (dict);
}
