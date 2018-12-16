/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:08:19 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/16 15:24:32 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_length(const char *format, int *i, t_format *arg_format)
{
	if (format[*i] && format[*i] == 'h' && format[*i + 1] == 'h')
	{
		arg_format->length = 'H';
		(*i) += 2;
	}
	else if (format[*i] && format[*i] == 'h')
	{
		arg_format->length = 'h';
		(*i)++;
	}
	else if (format[*i] && format[*i] == 'l' && format[*i + 1] == 'l')
	{
		arg_format->length = 'L';
		(*i) += 2;
	}
	else if (format[*i] && format[*i] == 'l')
	{
		arg_format->length = 'l';
		(*i)++;
	}
	else
		arg_format->length = '\0';
	return (0);
}
