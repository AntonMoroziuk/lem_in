/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:57:38 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/28 11:19:01 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	t;
	int		i;

	i = 0;
	t = (char)c;
	while (s[i])
		i++;
	while (i >= 0 && s[i] != t)
		i--;
	if (i == -1)
		return (NULL);
	return ((char*)s + i);
}
