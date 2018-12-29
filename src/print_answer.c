/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:15:52 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 14:02:55 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	is_good(t_path *path, t_map *map)
{
	t_path	*cur;
	int		sum;

	sum = 0;
	cur = map->pathes;
	while (cur != path)
	{
		sum += path->length - cur->length;
		cur = cur->next;
	}
	return (map->ants_count > sum);
}

static void	show_turn(t_path *path)
{
	t_ant	*cur;

	cur = path->ants;
	while (cur)
	{
		if (cur->pos == 0)
		{
			ft_printf("L%d-%s\n", cur->idx, path->vertixes[0]);
			cur->pos++;
			break ;
		}
		ft_printf("L%d-%s ", cur->idx, path->vertixes[cur->pos]);
		cur->pos++;
		if (cur->pos == path->length)
		{
			path->ants = cur->next;
			free(cur);
			cur = path->ants;
		}
		cur = cur->next;
	}
}

static void	move_ants(t_map *map)
{
	t_path	*cur;

	while (map->pathes->ants)
	{
		cur = map->pathes;
		while (cur)
		{
			show_turn(cur);
			cur = cur->next;
		}
	}
}

void		print_answer(t_map *map)
{
	t_path	*cur;
	int		start_number;

	start_number = map->ants_count;
	while (map->ants_count)
	{
		cur = map->pathes;
		//ft_putendl("here");
		while (cur)
		{
			if (is_good(cur, map))
				add_ant(cur, start_number - map->ants_count + 1);
			else
				break ;
			ft_putendl("here");
			cur = cur->next;
		}
	}
	move_ants(map);
}
