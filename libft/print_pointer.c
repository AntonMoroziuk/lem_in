/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:23:38 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/26 16:09:25 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_pointer(t_format arg_format, va_list args, int *count)
{
	if (arg_format.flags)
		arg_format.flags[0] = '\0';
	arg_format.length = 'l';
	arg_format.conv = 'x';
	ft_putstr("0x");
	*count += 2;
	return (print_uhex(arg_format, args, count));
}
