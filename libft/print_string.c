/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:09:28 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/01 12:43:32 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void				expand_str(char **str, char c, int add_to_left, int i)
{
	char	*extra;
	char	*temp;

	extra = ft_strnew(i);
	extra = ft_memset((void*)extra, c, i);
	temp = *str;
	if (add_to_left)
		*str = ft_strjoin(extra, *str);
	else
		*str = ft_strjoin(*str, extra);
	ft_strdel(&extra);
	ft_strdel(&temp);
}

static int				generate_str(t_format arg_format, char **output)
{
	char	*temp;

	if (ft_strlen(*output) > (size_t)arg_format.precision)
	{
		temp = *output;
		*output = ft_strsub(*output, 0, (size_t)arg_format.precision);
		ft_strdel(&temp);
	}
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

int						print_string(t_format arg_format,
	va_list args, int *count)
{
	char			*output;

	output = ft_strdup(va_arg(args, char *));
	if (!output)
		output = ft_strdup("(null)");
	if (arg_format.precision == -1)
		arg_format.precision = ft_strlen(output);
	if (generate_str(arg_format, &output))
		return (1);
	ft_putstr(output);
	*count += ft_strlen(output);
	ft_strdel(&output);
	return (0);
}
