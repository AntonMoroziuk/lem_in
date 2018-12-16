/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:34:00 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/30 18:18:33 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	find_end(char const *s, int start)
{
	int		end;

	end = start;
	while (s[end])
		end++;
	while (s[--end] == ' ' || s[end] == '\t' || s[end] == '\n')
		;
	return (end);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*res;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (!s[start])
		return (ft_strdup(""));
	end = find_end(s, start);
	if (!s[++end] && start == 0)
		return (ft_strdup(s));
	res = (char*)malloc(end - start + 1);
	if (res == NULL)
		return (NULL);
	i = -1;
	while (start < end)
		res[++i] = s[start++];
	res[++i] = '\0';
	return (res);
}
