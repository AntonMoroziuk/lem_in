/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:30:21 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/28 13:09:04 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (c < 0)
		c += 256;
	if (c > 255)
		c = c % 256;
	while (i < n && ((unsigned char*)src)[i] != c)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		return ((void*)((unsigned char*)dest + i + 1));
	}
}
