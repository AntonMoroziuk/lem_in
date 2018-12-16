/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:48:47 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/16 15:24:13 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		pseudo_atoi(const char *str, int start)
{
	int		res;

	res = 0;
	while (ft_isdigit(str[start]))
	{
		res = res * 10 + str[start] - '0';
		start++;
	}
	return (res);
}

int				get_mfw(const char *format, int *i, int start,
	t_format *arg_format)
{
	int		j;
	int		mfw;

	j = 0;
	while (ft_isdigit(format[start + j]))
		j++;
	mfw = pseudo_atoi(format, start);
	if (mfw)
		arg_format->mfw = mfw;
	(*i) += j;
	return (0);
}

static void		neg_precision(const char *format, int *i, t_format *arg_format)
{
	int		j;

	if (!arg_format->flags)
		arg_format->flags = ft_strdup("-");
	else
	{
		j = 0;
		while (arg_format->flags[j])
			j++;
		arg_format->flags[j] = '-';
	}
	(*i)++;
	get_mfw(format, i, *i, arg_format);
}

int				get_precision(const char *format, int *i, t_format *arg_format)
{
	int		j;

	j = 0;
	arg_format->precision = -1;
	if (format[*i] == '.' && format[*i + 1] == '-')
	{
		(*i)++;
		neg_precision(format, i, arg_format);
	}
	else if (format[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(format[*i + j]))
			j++;
		arg_format->precision = pseudo_atoi(format, *i);
		(*i) += j;
	}
	return (0);
}
