/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:57:46 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/26 13:57:01 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static int						generate_str(unsigned char nb,
	t_format arg_format, char **output)
{
	MALLOCCHECK_INT((*output = ft_strnew(2)));
	(*output)[0] = (char)nb;
	if (1 < (size_t)arg_format.mfw)
	{
		if (!arg_format.flags)
			expand_str(output, ' ', 1, arg_format.mfw - 1);
		else if (ft_strchr(arg_format.flags, '-'))
			expand_str(output, ' ', 0, arg_format.mfw - 1);
		else if (ft_strchr(arg_format.flags, '0'))
			expand_str(output, '0', 1, arg_format.mfw - 1);
		else
			expand_str(output, ' ', 1, arg_format.mfw - 1);
	}
	return (0);
}

int								print_char(t_format arg_format,
	va_list args, int *count)
{
	unsigned char			nb;
	char					*output;

	nb = (unsigned char)va_arg(args, int);
	if (check_if_null(nb, &arg_format, count))
		return (0);
	if (arg_format.precision == -1)
		arg_format.precision = 0;
	if (generate_str(nb, arg_format, &output))
		return (1);
	if (nb == 0)
	{
		ft_putstr(output);
		ft_putchar(0);
		ft_putstr(ft_strchr(output, '\0'));
		*count += ft_strlen(output) + ft_strlen(ft_strchr(output, '\0')) + 1;
	}
	else
	{
		ft_putstr(output);
		*count += ft_strlen(output);
	}
	free(output);
	return (0);
}
