/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:06:18 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/09 14:08:01 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"

typedef struct		s_map
{
	char			*line;
	struct s_map	*next;
}					t_map;
typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	int				index;
	int				ant_on;
	struct s_rooms	*next;
}					t_rooms;
typedef struct		s_lem_in
{
	int				ants;
	int				nb_rooms;
	int				**mat_co;
	t_rooms			*begin_list;
	t_rooms			*start;
	t_rooms			*end;
	t_map			*map;
}					t_lem_in;
typedef struct		s_path
{
	int				*path;
	int				nb_mv;
	struct s_path	*next;
}					t_path;
void				ft_read_file(t_lem_in *data);
void				ft_print_error(char *error, t_lem_in *data, t_path *path);
int					ft_checkrooms(char *line, t_lem_in *data);
t_rooms				*ft_creatroom(char *line, t_lem_in *data);
void				ft_push_in_lst(t_rooms *new_link, t_lem_in *data);
int					ft_lenlst(t_rooms *begin_list);
void				ft_free_tab(int **tab, int size);
int					ft_lenlst(t_rooms *begin_list);
int					ft_check_connect(char *line, t_lem_in *data);
void				ft_getinfo(char *line, int type, t_lem_in *data);
void				ft_find_paths(t_lem_in *data);
int					ft_get_path(t_lem_in *data, t_path *paths, int *path,\
		int start);
void				ft_sort(t_path *paths);
void				ft_clean_path(t_path *paths);
void				ft_push_ant(t_lem_in *data, t_path *paths);
void				ft_push_line_back(t_lem_in *data, char *line);
void				ft_print_st(int to_push, t_path *paths, t_rooms *rooms,\
		int *pushed);
void				ft_print_mv_ant(t_rooms *begin_list, t_path *paths);
void				ft_mv_ant(t_path *paths, t_lem_in *data);
int					ft_checksup_to_int(char *line);
#endif
