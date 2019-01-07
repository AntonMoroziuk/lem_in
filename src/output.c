#include "../includes/lem_in.h"

static void	print_map(t_map *map)
{
	t_input	*cur;

	cur = map->input;
	while (cur)
	{
		ft_putendl(cur->line);
		cur = cur->next;
	}
}

void		format_output(int argc, char **argv, t_map *map)
{
	if (argc == 1)
	{
		print_map(map);
		ft_putchar('\n');
		print_answer(map);
	}
	else if (ft_strequ(argv[1], "-s"))
		print_answer(map);
	else if (ft_strequ(argv[1], "-c"))
		print_count(map);
}