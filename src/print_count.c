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
		if (!cur->next || cur->pos == 0)
		{
			cur->pos++;
			break ;
		}
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

static int	move_ants(t_map *map)
{
	t_path	*cur;
	int		count;

	count = 0;
	while (map->pathes->ants)
	{
		cur = map->pathes;
		while (cur)
		{
			show_turn(cur);
			if (!cur->next)
				count++;
			cur = cur->next;
		}
	}
	return (count);
}

void		print_count(t_map *map)
{
	t_path	*cur;
	int		start_number;
	int		count;

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
	count = move_ants(map);
	ft_printf("%d\n", count);
}