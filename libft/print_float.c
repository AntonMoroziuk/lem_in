/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:41:09 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/26 13:54:26 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				check_sign(char **str, double nb,
	t_format arg_format)
{
	char			*temp;

	if (arg_format.flags)
	{
		if (ft_strchr(arg_format.flags, '+'))
		{
			if (nb > 0)
			{
				temp = *str;
				*str = ft_strjoin("+", *str);
				ft_strdel(&temp);
			}
		}
		else if (ft_strchr(arg_format.flags, ' '))
		{
			if (nb > 0)
			{
				temp = *str;
				*str = ft_strjoin(" ", *str);
				ft_strdel(&temp);
			}
		}
	}
}

static void				expand_str(char **str, char c, int add_to_left, int i)
{
	char	*temp;
	char	*extra;
	char	*sign;

	extra = ft_strnew(i);
	extra = ft_memset((void*)extra, c, i);
	temp = *str;
	if (add_to_left)
	{
		sign = ft_strsub(*str, 0, 1);
		if (!ft_isdigit(sign[0]) && c == '0')
		{
			*str = ft_strjoin(extra, ft_strsub(*str, 1, ft_strlen(*str) - 1));
			ft_strdel(&temp);
			temp = *str;
			*str = ft_strjoin(sign, *str);
		}
		else
			*str = ft_strjoin(extra, *str);
		ft_strdel(&sign);
	}
	else
		*str = ft_strjoin(*str, extra);
	ft_strdel(&temp);
	ft_strdel(&extra);
}

static int				generate_str(double nb, t_format arg_format,
	char **output)
{
	if (nb < 0)
		*output = ft_strjoin("-", ft_doubleitoa(-nb, arg_format.precision));
	else
		*output = ft_doubleitoa(nb, arg_format.precision);
	check_sign(output, nb, arg_format);
	if (arg_format.precision == 0 && arg_format.flags &&
		ft_strchr(arg_format.flags, '#'))
		expand_str(output, '.', 0, 1);
	if (ft_strlen(*output) < (size_t)arg_format.mfw)
	{
		if (!arg_format.flags)
			expand_str(output, ' ', 1, arg_format.mfw - ft_strlen(*output));
		else if (ft_strchr(arg_format.flags, '-'))
			expand_str(output, ' ', 0, arg_format.mfw - ft_strlen(*output));
		else if (ft_strchr(arg_format.flags, '0'))
			expand_str(output, '0', 1, arg_format.mfw - ft_strlen(*output));
		else
			expand_str(output, ' ', 1, arg_format.mfw - ft_strlen(*output));
	}
	return (0);
}

int						print_float(t_format arg_format,
	va_list args, int *count)
{
	double	nb;
	char	*output;

	nb = va_arg(args, double);
	if (check_if_null(nb, &arg_format, count))
		return (0);
	if (arg_format.precision == -1)
		arg_format.precision = 6;
	if (generate_str(nb, arg_format, &output))
		return (1);
	ft_putstr(output);
	*count += ft_strlen(output);
	ft_strdel(&output);
	return (0);
}
