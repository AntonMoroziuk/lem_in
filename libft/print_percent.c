/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:10:25 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/26 13:55:09 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	expand_str(char **str, char c, int add_to_left, int i)
{
	char	*temp;
	char	*extra;

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

static int	generate_str(t_format arg_format,
	char **output)
{
	*output = ft_strdup("%");
	if (ft_strlen(*output) < (size_t)arg_format.mfw)
	{
		if (!arg_format.flags)
			expand_str(output, ' ', 1, arg_format.mfw - ft_strlen(*output));
		else if (ft_strchr(arg_format.flags, '-'))
			expand_str(output, ' ', 0, arg_format.mfw - ft_strlen(*output));
		else if (ft_strchr(arg_format.flags, '0') && arg_format.precision == 0)
			expand_str(output, '0', 1, arg_format.mfw - ft_strlen(*output));
		else
			expand_str(output, ' ', 1, arg_format.mfw - ft_strlen(*output));
	}
	return (0);
}

int			print_percent(t_format arg_format, int *count)
{
	char			*output;

	if (arg_format.precision == -1)
		arg_format.precision = 0;
	if (generate_str(arg_format, &output))
		return (1);
	ft_putstr(output);
	*count += ft_strlen(output);
	ft_strdel(&output);
	return (0);
}
