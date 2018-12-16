/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:11:00 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/26 13:53:13 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void						uhex_itoa(unsigned long long int nb,
	char first_letter, char **res)
{
	int						size;
	int						i;
	unsigned long long int	temp;

	size = (nb == 0);
	temp = nb;
	while (temp != 0)
	{
		temp /= 16;
		size++;
	}
	*res = ft_strnew(size);
	if (*res)
	{
		while (size >= 0)
		{
			i = nb % 16;
			if (i < 10)
				(*res)[--size] = (char)(i + '0');
			else
				(*res)[--size] = (char)(i - 10 + first_letter);
			nb /= 16;
		}
	}
}

static unsigned	long long int	get_arg(t_format arg_format, va_list args)
{
	if (arg_format.length == 'L')
		return ((unsigned long long int)va_arg(args, long long int));
	else if (arg_format.length == 'l')
		return ((unsigned long int)va_arg(args, long int));
	else if (arg_format.length == 'h')
		return ((unsigned short int)va_arg(args, int));
	else if (arg_format.length == 'H')
		return ((unsigned char)va_arg(args, int));
	return ((unsigned int)va_arg(args, int));
}

static void						expand_str(char **str, char c,
	int add_to_left, int i)
{
	char					*temp;
	char					*extra;

	extra = ft_strnew(i);
	extra = ft_memset((void*)extra, c, i);
	temp = *str;
	if (add_to_left)
		*str = ft_strjoin(extra, *str);
	else
		*str = ft_strjoin(*str, extra);
	ft_strdel(&temp);
	ft_strdel(&extra);
}

static int						generate_str(unsigned long long int nb,
	t_format arg_format, char **output, char letter)
{
	uhex_itoa(nb, letter - 23, output);
	if (ft_strlen(*output) < (size_t)arg_format.precision)
		expand_str(output, '0', 1, arg_format.precision - ft_strlen(*output));
	if (arg_format.flags && ft_strlen(*output) - (ft_strchr(arg_format.flags,
		'#') != 0) * 2 < (size_t)arg_format.mfw && ft_strchr(arg_format.flags,
		'0') && arg_format.precision == 0 && !ft_strchr(arg_format.flags, '-'))
		expand_str(output, '0', 1, arg_format.mfw - ft_strlen(*output)
			- (ft_strchr(arg_format.flags, '#') != 0) * 2);
	if (arg_format.flags && ft_strchr(arg_format.flags, '#') && nb != 0)
	{
		expand_str(output, letter, 1, 1);
		expand_str(output, '0', 1, 1);
	}
	if (ft_strlen(*output) < (size_t)arg_format.mfw)
	{
		if (!arg_format.flags)
			expand_str(output, ' ', 1, arg_format.mfw - ft_strlen(*output));
		else if (ft_strchr(arg_format.flags, '-'))
			expand_str(output, ' ', 0, arg_format.mfw - ft_strlen(*output));
		else
			expand_str(output, ' ', 1, arg_format.mfw - ft_strlen(*output));
	}
	return (0);
}

int								print_uhex(t_format arg_format,
	va_list args, int *count)
{
	unsigned long long int	nb;
	char					*output;

	nb = get_arg(arg_format, args);
	if (check_if_null(nb, &arg_format, count))
		return (0);
	if (arg_format.precision == -1)
		arg_format.precision = 0;
	if (arg_format.conv == 'x')
		generate_str(nb, arg_format, &output, 'x');
	else
		generate_str(nb, arg_format, &output, 'X');
	ft_putstr(output);
	*count += ft_strlen(output);
	ft_strdel(&output);
	return (0);
}
