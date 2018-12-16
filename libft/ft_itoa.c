/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:23:41 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/27 12:35:53 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	get_size(long long int n)
{
	int		size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char		*ft_itoa(long long int n)
{
	int		i;
	int		k;
	int		size;
	char	*res;

	i = 0;
	size = get_size(n);
	res = (char*)malloc(size + 1);
	if (res == NULL)
		return (NULL);
	if (n < 0)
		res[i++] = '-';
	res[size--] = '\0';
	while (size >= i)
	{
		k = n % 10;
		if (k < 0)
			k *= -1;
		res[size] = k + '0';
		size--;
		n /= 10;
	}
	return (res);
}
