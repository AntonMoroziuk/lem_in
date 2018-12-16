/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 10:54:45 by amoroziu          #+#    #+#             */
/*   Updated: 2018/10/30 18:20:41 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*map;
	t_list	*new;

	map = NULL;
	if (f == NULL)
		return (NULL);
	while (lst)
	{
		if ((new = (*f)(lst)))
		{
			new = ft_lstnew(new->content, new->content_size);
			if (new == NULL)
				return (NULL);
			ft_lstpushback(&map, new);
		}
		lst = lst->next;
	}
	return (map);
}
