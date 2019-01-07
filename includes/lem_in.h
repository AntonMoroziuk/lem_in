/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:19:12 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 15:41:06 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_node	t_node;
typedef struct s_room	t_room;
struct			s_node
{
	t_room				*room;
	t_node				*next;
};
struct			s_room
{
	char				*name;
	t_node				*adj;
	t_room				*next;
	int					inputs;
	int					outputs;
	int					bfs_level;
	int					dist_to_end;
	int					x;
	int					y;
};

typedef struct	s_queue_node
{
	t_node				*node;
	struct s_queue_node	*next;
}				t_queue_node;

typedef struct	s_queue
{
	t_queue_node		*head;
	t_queue_node		*tail;
}				t_queue;

typedef struct	s_link
{
	char				*first;
	char				*second;
	struct s_link		*next;
}				t_link;

typedef struct	s_ant
{
	int					pos;
	int					idx;
	struct s_ant		*next;
}				t_ant;

typedef struct	s_path
{
	char				**vertixes;
	t_ant				*ants;
	int					ants_number;
	int					length;
	struct s_path		*next;
}				t_path;

typedef struct	s_input
{
	char				*line;
	struct s_input		*next;
}				t_input;

typedef struct	s_map
{
	int					rooms_count;
	int					ants_count;
	int					max_bfs;
	char				**rooms_array;
	t_input				*input;
	t_room				*rooms;
	t_room				*start;
	t_room				*end;
	t_link				*links;
	t_path				*pathes;
}				t_map;

void			delete_rooms(t_room *head);
void			delete_room(t_room *room);
void			delete_links(t_link *head);
void			delete_pathes(t_path *head);
void			work_with_map(t_map *map);
void			print_answer(t_map *map);
void			add_ant(t_path *cur, int ant_idx);
void			queue_pushback(t_node *node, t_queue *queue);
int				get_map(t_map *map);
int				get_rooms_idx(char *name, t_map *map);
int				incorrect_room(t_room *room, t_map *map);
int				incorrect_link(t_map *map, t_link *link);
int				proceed_line(char *line, t_map *map);
int				get_pathes(t_map *map);
int				no_start_or_end(t_map *map);
void			add_room(t_map *map, t_room *room);
void			create_pathes(t_map *map);
void			add_link_to_rooms(t_map *map, t_link *link);
void			add_to_input(t_map *map, char *str);
void			count_inputs_outputs(t_map *map);
void			allign_links(t_map *map);
void			delete_dead_ends(t_map *map);
void			delete_input_forks(t_map *map);
void			delete_output_forks(t_map *map);
void			remove_node(t_room *room, t_node **to_remove, t_node *prev);
void			remove_room_from_adj(t_map *map, t_room *room);
void			remove_link(t_link **to_delete, t_link *prev, t_map *map);
void			remove_links_with_room(t_map *map, t_room *room);
void			print_count(t_map *map);
void			format_output(int argc, char **argv, t_map *map);
t_room			*get_room(char *str, t_map *map);
t_room			*room_with_name(char *name, t_map *map);
t_node			*queue_popfront(t_queue *queue);
t_node			*initialize_queue(t_queue *queue, t_map *map);
t_room			*get_room(char *name, t_map *map);

#endif
