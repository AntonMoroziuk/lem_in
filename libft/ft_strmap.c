/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:35:42 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/30 16:39:23 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	count(char const *s, char (*f)(char))
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((*f)(s[i]))
			count++;
		i++;
	}
	return (count);
}

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	str = (char*)malloc(count(s, f) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		if ((*f)(s[i]))
		{
			str[j] = (*f)(s[i]);
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
