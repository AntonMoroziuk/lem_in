/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:15:52 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/09 11:02:58 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	is_good(t_path *path, t_map *map)
{
	t_path	*cur;
	int		sum;

	sum = 0;
	cur = map->pathes;
	if (map->ants_count <= path->length - map->pathes->length)
		return (0);
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
			ft_printf("L%d-%s", cur->idx, path->vertixes[0]);
			cur->pos++;
			break ;
		}
		ft_printf("L%d-%s", cur->idx, path->vertixes[cur->pos]);
		if (cur->next)
			ft_putchar(' ');
		cur->pos++;
		cur = cur->next;
	}
	if (path->ants && path->ants->pos == path->length)
	{
		cur = path->ants;
		path->ants = path->ants->next;
		free(cur);
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
			if (!cur->next)
				ft_putchar('\n');
			else
				ft_putchar(' ');
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
		while (cur)
		{
			if (is_good(cur, map))
			{
				add_ant(cur, start_number - map->ants_count + 1);
				map->ants_count--;
			}
			else
				break ;
			cur = cur->next;
		}
	}
	move_ants(map);
}
