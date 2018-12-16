/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:19:12 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/16 15:13:39 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_room
{
	char			*name;
	struct s_room	*next;
	int				x;
	int				y;
}				t_room;

typedef struct	s_node
{
	struct s_node	*next;
	t_room			*room;
}				t_node;

typedef struct	s_path
{
	t_node			*head;
	int				length;
}				t_path;

typedef struct	s_link
{
	char			*first;
	char			*second;
	struct s_link	*next;
}				t_link;

typedef struct	s_map
{
	int				rooms_count;
	int				ants_count;
	char			*rooms_array;
	int				**matrix;
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	t_link			*links;
}				t_map;

void			delete_rooms(t_room *head);
void			delete_room(t_room *room);
void			delete_links(t_link *head);
int				get_map(t_map *map);
int				incorrect_room(t_room *room, t_map *map);
int				incorrect_link(t_map *map, t_link *link);
int				proceed_line(char *line, t_map *map);
void			add_room(t_map *map, t_room *room);
t_room			*get_room(char *str, t_map *map);

#endif
