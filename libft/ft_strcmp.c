/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 11:38:57 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/28 15:25:27 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*f;
	unsigned char	*s;

	i = 0;
	f = (unsigned char*)s1;
	s = (unsigned char*)s2;
	while (f[i] && f[i] == s[i])
		i++;
	return (f[i] - s[i]);
}
