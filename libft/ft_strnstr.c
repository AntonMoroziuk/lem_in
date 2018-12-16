/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:12:51 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/28 15:17:15 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			k = 0;
			while (haystack[i + k] == needle[k] && needle[k] && haystack[i + k]
					&& len > i + k)
				k++;
			if (needle[k] == '\0')
				return ((char*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
