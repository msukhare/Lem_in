/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant_in_rooms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 09:57:06 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/10 10:17:51 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_rooms	*ft_get_rm_id(t_rooms *rooms, int index)
{
	while (rooms && rooms->index != index)
		rooms = rooms->next;
	return (rooms);
}

void			ft_print_mv_ant(t_rooms *begin_list, t_path *paths)
{
	t_rooms		*rooms;
	int			i;

	while (paths)
	{
		i = (paths->nb_mv - 2);
		while (i > 0)
		{
			rooms = ft_get_rm_id(begin_list, paths->path[i]);
			if (rooms->ant_on != 0)
				ft_printf("L%d-%s ", rooms->ant_on, rooms->name);
			i--;
		}
		paths = paths->next;
	}
}

void			ft_print_st(int to_push, t_path *paths, t_rooms *rooms,\
		int *pushed)
{
	t_rooms		*tmp;

	while (to_push > 0 && paths)
	{
		tmp = rooms;
		while (tmp && tmp->index != paths->path[1])
			tmp = tmp->next;
		ft_printf("L%d-%s ", *pushed, tmp->name);
		tmp->ant_on = *pushed;
		(*pushed)++;
		paths = paths->next;
		--to_push;
	}
}

void			ft_mv_ant(t_path *paths, t_lem_in *data)
{
	t_rooms		*rooms;
	t_rooms		*next_room;
	int			i;

	while (paths)
	{
		i = (paths->nb_mv - 2);
		while (i > 0)
		{
			rooms = ft_get_rm_id(data->begin_list, paths->path[i]);
			if (rooms->ant_on != 0)
			{
				next_room = ft_get_rm_id(data->begin_list, paths->path[i + 1]);
				if (next_room == data->end)
					data->end->ant_on++;
				else
					next_room->ant_on = rooms->ant_on;
				if (next_room == data->end)
					ft_printf("L%d-%s ", rooms->ant_on, data->end->name);
				rooms->ant_on = 0;
			}
			i--;
		}
		paths = paths->next;
	}
}
