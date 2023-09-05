/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_dict_values_setup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:21:12 by marvin            #+#    #+#             */
/*   Updated: 2023/05/14 20:21:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

void	nc_dict_values_setup(t_dict *dict, void *(*valcpy)(void *), \
	void (*valdel)(void *), char *(*valstr)(void *))
{
	dict->valcpy = valcpy;
	dict->valdel = valdel;
	dict->valstr = valstr;
}
