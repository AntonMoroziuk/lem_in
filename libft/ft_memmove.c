/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 13:34:18 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/28 14:14:27 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = (char*)dst;
	source = (char*)src;
	if (dest == source)
		return (dest);
	if (source < dest)
	{
		source = source + len - 1;
		dest = dest + len - 1;
		while (len--)
			*dest-- = *source--;
	}
	else
		while (len--)
			*dest++ = *source++;
	return (dst);
}
