/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:33:15 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/30 17:09:10 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (c < 0)
		c += 256;
	if (c >= 256)
		c = c % 256;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == c)
			return ((void*)((unsigned char*)s + i));
		i++;
	}
	return (NULL);
}
