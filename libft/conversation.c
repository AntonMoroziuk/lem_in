/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:17:52 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/16 15:25:23 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isconversation(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
			c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f'
			|| c == '%');
}

int				get_convers(const char *format, int *i, t_format *arg_format)
{
	arg_format->conv = format[*i];
	if (isconversation(format[*i]))
		(*i)++;
	return (0);
}
