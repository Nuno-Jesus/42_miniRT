/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:46:42 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/06/29 19:49:40 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnc.h"

char	*nc_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	len = nc_strlen(s1) + nc_strlen(s2);
	res = (char *)malloc(len + 1);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	nc_strlcat(res, s1, len + 1);
	nc_strlcat(res, s2, len + 1);
	return (res);
}
