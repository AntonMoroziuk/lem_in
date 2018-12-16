/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleitoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:02:19 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/26 14:03:20 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_power(double *nb)
{
	int		power;

	power = 0;
	while (*nb >= 1.0)
	{
		power++;
		*nb /= 10;
	}
	return (power);
}

static char	*get_bddigits(double *nb)
{
	char	*res;
	int		power;
	int		i;

	power = get_power(nb);
	res = ft_strnew(power);
	i = -1;
	while (power > 0)
	{
		res[++i] = (int)(*nb * 10) + '0';
		*nb = *nb * 10.0 - (int)(*nb * 10);
		power--;
	}
	return (res);
}

static char	*get_addigits(double *nb, int precision)
{
	char	*res;
	int		i;

	MALLOCCHECK_NULL((res = ft_strnew(precision + 1)));
	i = -1;
	if (precision > 0)
	{
		res[++i] = '.';
		if (*nb > 1)
			*nb = *nb - (long long int)(*nb);
		while (++i <= precision)
		{
			*nb *= 10;
			res[i] = (int)(*nb) + '0';
			*nb -= (int)(*nb);
		}
	}
	return (res);
}

char		*ft_doubleitoa(double nb, int precision)
{
	char	*part1;
	char	*part2;
	char	*res;

	if (nb < 9223372036854775807)
	{
		part1 = ft_itoa((long long int)nb);
		part2 = get_addigits(&nb, precision);
		res = ft_strjoin(part1, part2);
		ft_strdel(&part1);
		ft_strdel(&part2);
		return (res);
	}
	part1 = get_bddigits(&nb);
	part2 = get_addigits(&nb, precision);
	res = ft_strjoin(part1, part2);
	ft_strdel(&part1);
	ft_strdel(&part2);
	return (res);
}
