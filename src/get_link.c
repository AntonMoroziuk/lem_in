/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:43:25 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/10 12:29:46 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		add_link(t_map *map, t_link *link)
{
	t_link	*cur;

	if (!map->links)
		map->links = link;
	else
	{
		cur = map->links;
		while (cur->next)
			cur = cur->next;
		cur->next = link;
	}
}

static t_link	*new_link(char *first_name, char *second_name, t_map *map)
{
	t_link	*new;

	new = (t_link*)malloc(sizeof(t_link));
	new->first = room_with_name(first_name, map);
	new->second = room_with_name(second_name, map);
	new->next = NULL;
	ft_strdel(&first_name);
	ft_strdel(&second_name);
	if (!new->first || !new->second)
	{
		free(new);
		ft_putendl("ERROR: Room does not exist!");
		return (NULL);
	}
	return (new);
}

static int		get_names(char *str, char **first_name, char **second_name)
{
	int		i;

	i = -1;
	*first_name = NULL;
	*second_name = NULL;
	while (str[++i] && str[i] != '-')
		;
	if (!str[i])
		return (0);
	*first_name = ft_strsub(str, 0, i);
	while (str[++i] && str[i] != '-')
		;
	if (str[i])
		return (0);
	*second_name = ft_strsub(ft_strchr(str, '-'),
							1, ft_strlen(ft_strchr(str, '-')));
	return (1);
}

int				get_link(char *str, t_map *map)
{
	t_link	*new;
	char	*first_name;
	char	*second_name;

	if (!get_names(str, &first_name, &second_name))
	{
		if (first_name)
			ft_strdel(&first_name);
		if (second_name)
			ft_strdel(&second_name);
		return (0);
	}
	new = new_link(first_name, second_name, map);
	if (new && !incorrect_link(map, new))
	{
		add_link(map, new);
		return (1);
	}
	return (0);
}
