/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 18:58:13 by crypto            #+#    #+#             */
/*   Updated: 2023/06/29 19:50:33 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if ((!big || !little) && len == 0)
		return (NULL);
	i = 0;
	little_len = nc_strlen(little);
	if (!little[0])
		return ((char *)big);
	while (big[i] != '\0' && i <= len - little_len && len > 0)
	{
		if (big[i] == little[0])
			if (!nc_memcmp(big + i, little, little_len))
				return ((char *)big + i);
		i++;
	}
	return (NULL);
}
