/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:49:49 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/26 16:09:52 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		print_arg(t_format arg_format, va_list args, int *count)
{
	if (arg_format.conv == 'c')
		return (print_char(arg_format, args, count));
	if (arg_format.conv == 's')
		return (print_string(arg_format, args, count));
	if (arg_format.conv == 'p')
		return (print_pointer(arg_format, args, count));
	if (arg_format.conv == 'd' || arg_format.conv == 'i')
		return (print_sdecimal(arg_format, args, count));
	if (arg_format.conv == 'o')
		return (print_uoctal(arg_format, args, count));
	if (arg_format.conv == 'u')
		return (print_udecimal(arg_format, args, count));
	if (arg_format.conv == 'x' || arg_format.conv == 'X')
		return (print_uhex(arg_format, args, count));
	if (arg_format.conv == 'f')
		return (print_float(arg_format, args, count));
	if (arg_format.conv == '%')
		return (print_percent(arg_format, count));
	return (1);
}

static int		prepare_arg(va_list args, const char *format, int *i,
		int *count)
{
	t_format	arg_format;

	(*i)++;
	if ((get_format(format, i, &arg_format)))
		return (1);
	if (print_arg(arg_format, args, count))
	{
		if (arg_format.flags)
			ft_strdel(&(arg_format.flags));
		return (1);
	}
	if (arg_format.flags)
		ft_strdel(&(arg_format.flags));
	return (0);
}

int				ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	count = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			count++;
		}
		else
		{
			prepare_arg(args, format, &i, &count);
			i--;
		}
	}
	va_end(args);
	return (count);
}
