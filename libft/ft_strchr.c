/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:54:11 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/28 11:20:28 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	t;

	i = 0;
	t = (char)c;
	while (s[i] && s[i] != t)
		i++;
	if (s[i] == t)
		return ((char*)s + i);
	else
		return (NULL);
}
