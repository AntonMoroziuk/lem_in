/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:29:24 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/01 12:43:03 by amoroziu         ###   ########.fr       */
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

int			check_if_null(unsigned long long int nb, t_format *arg_format,
	int *count)
{
	char	*output;

	if (nb == 0 && arg_format->precision == 0)
	{
		output = ft_strnew(0);
		if (arg_format->flags && ft_strchr(arg_format->flags, '-') &&
			arg_format->mfw > 0)
			expand_str(&output, ' ', 0, arg_format->mfw);
		else if (arg_format->mfw)
			expand_str(&output, ' ', 1, arg_format->mfw);
		ft_putstr(output);
		*count += ft_strlen(output);
		ft_strdel(&output);
		return (1);
	}
	return (0);
}
