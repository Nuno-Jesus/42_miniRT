/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:27:12 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/05 12:10:38 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

bool	nc_isnum(char *str, char *delims)
{
	if (*str == '-')
		++str;
	if (nc_strchr(delims, *str) || *str == '\0')
		return (false);
	while (*str && !nc_strchr(delims, *str))
		if (!nc_isdigit(*str++))
			return (false);
	return (true);
}
