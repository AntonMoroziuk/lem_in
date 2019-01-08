/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:31:24 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/08 14:31:55 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_input	*cur;

	if (argc == 1)
	{
		print_map(map);
		ft_putchar('\n');
		print_answer(map);
	}
	else if (ft_strequ(argv[1], "-s"))
		print_answer(map);
	else if (ft_strequ(argv[1], "-c"))
	{
		cur = map->input;
		while (cur->next)
			cur = cur->next;
		print_count(map);
		ft_putendl(cur->line);
	}
}
