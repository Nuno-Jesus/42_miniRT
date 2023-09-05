/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_pair_tostring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:07:08 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 15:07:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_pair_tostring(t_pair *pair, char *(*keystr)(void *), \
	char *(*valstr)(void *))
{
	char	*key;
	char	*value;
	char	*tmp;
	char	*res;

	if (!pair || !keystr || !valstr)
		return (NULL);
	key = keystr(pair->key);
	value = valstr(pair->value);
	tmp = nc_strjoin("pair[\'", key);
	res = nc_strjoin(tmp, "\']=\'");
	free(tmp);
	tmp = nc_strjoin(res, value);
	free(res);
	res = nc_strjoin(tmp, "\'");
	free(tmp);
	free(value);
	free(key);
	return (res);
}
