/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_pair_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:32:12 by marvin            #+#    #+#             */
/*   Updated: 2023/05/13 14:32:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_pair_print(t_pair *pair, char *(*keystr)(void *), \
	char *(*valstr)(void *))
{
	char	*key;
	char	*value;

	if (!keystr || !valstr)
		return ;
	key = keystr(pair->key);
	value = valstr(pair->value);
	nc_putstr_fd("pair[", STDOUT_FILENO);
	nc_putstr_fd(key, STDOUT_FILENO);
	nc_putstr_fd("]=", STDOUT_FILENO);
	nc_putendl_fd(value, STDOUT_FILENO);
	free(key);
	free(value);
}
