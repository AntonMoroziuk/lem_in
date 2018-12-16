/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:04:08 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/28 15:15:48 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		k;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			k = 0;
			while (haystack[i + k] == needle[k] && needle[k] && haystack[i + k])
				k++;
			if (needle[k] == '\0')
				return ((char*)haystack + i);
		}
		i++;
	}
	return (NULL);
}
