/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:40:29 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/27 11:40:30 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*res;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((char*)res)[i] = 0;
		i++;
	}
	return (res);
}
