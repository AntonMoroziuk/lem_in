/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:33:50 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/30 18:39:33 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	size = ft_strlen(dst) + ft_strlen(src);
	if (dstsize == 0 || dstsize - 1 < ft_strlen(dst))
		size = ft_strlen(src) + dstsize;
	while (dst[i])
		i++;
	j = 0;
	if (dstsize != 0 && dstsize != 1)
	{
		while (src[j] && i < dstsize - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (size);
}
