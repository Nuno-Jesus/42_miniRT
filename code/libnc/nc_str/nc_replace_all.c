/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_replace_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:35:18 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 15:35:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_replace_all(char *str, char *old, char *new)
{
	char	*res;
	char	*tmp;

	res = nc_strdup(str);
	while (nc_strnstr(res, old, nc_strlen(res)))
	{
		tmp = res;
		res = nc_replace(res, old, new);
		free(tmp);
	}
	return (res);
}
