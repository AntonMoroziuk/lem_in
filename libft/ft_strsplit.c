/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:28:42 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/30 18:00:48 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static char		*get_word(char const *s, char c, int *i)
{
	char	*word;
	int		length;
	int		j;

	length = *i;
	j = 0;
	while (s[length] && s[length] != c)
		length++;
	word = (char*)malloc(length - *i + 1);
	while (*i < length)
	{
		word[j] = s[*i];
		(*i)++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	res = (char**)malloc(sizeof(char*) * (words + 1));
	if (res == NULL)
		return (NULL);
	res[words] = NULL;
	i = 0;
	j = -1;
	while (s[i] && s[i] == c)
		i++;
	while (++j < words)
	{
		res[j] = get_word(s, c, &i);
		if (res[j] == NULL)
			return (NULL);
		while (s[i] && s[i] == c)
			i++;
	}
	return (res);
}
