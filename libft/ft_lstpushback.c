/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:57:10 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/30 18:03:42 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			cur = *lst;
			while (cur->next)
				cur = cur->next;
			cur->next = new;
		}
	}
}
