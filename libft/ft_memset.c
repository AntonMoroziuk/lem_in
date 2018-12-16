/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:32:47 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/28 11:24:50 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	byte;
	size_t			i;

	byte = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		((unsigned char*)b)[i] = byte;
		i++;
	}
	return (b);
}
