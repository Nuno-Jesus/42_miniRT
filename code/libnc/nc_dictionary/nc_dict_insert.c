/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dict_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:07:00 by marvin            #+#    #+#             */
/*   Updated: 2023/05/14 17:07:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_dict_insert(t_dict *dict, void *key, void *value)
{
	t_pair		*pair;

	if (!dict || !key)
		return ;
	if (nc_dict_exists(dict, key))
	{
		pair = nc_dict_get(dict, key);
		nc_pair_print(pair, nc_strdup, nc_strdup);
		nc_pair_clear(pair, dict->keydel, dict->valdel);
		*pair = (t_pair){.key = key, .value = value};
		return ;
	}
	pair = nc_pair_new(key, value);
	if (!pair)
		return ;
	dict->pairs = nc_bstree_insert(dict->pairs, pair, dict->keycmp, 0);
	dict->size++;
}
