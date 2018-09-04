/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_ant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:16:20 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/09 17:38:44 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_put_in_rooms(t_path *paths, int ant)
{
	int		to_push;
	t_path	*rooms;

	to_push = 1;
	rooms = paths;
	paths = paths->next;
	while (paths)
	{
		if ((rooms->nb_mv + (ant - to_push)) > paths->nb_mv)
			to_push++;
		else
			return (to_push);
		rooms = paths;
		paths = paths->next;
	}
	return (to_push);
}

static void	ft_print_map(t_map *map)
{
	while (map)
	{
		ft_printf("%s\n", map->line);
		map = map->next;
	}
	ft_putchar('\n');
}

static void	ft_put_in_end(t_path *paths, t_lem_in *data)
{
	int		pushed;

	pushed = 1;
	while (pushed <= data->ants)
	{
		ft_printf("L%d-%s ", pushed, data->end->name);
		pushed++;
	}
	ft_putchar('\n');
	ft_print_error(NULL, data, paths);
}

void		ft_push_ant(t_lem_in *data, t_path *paths)
{
	int		to_push_st;
	int		pushed;

	pushed = 1;
	data->start->ant_on = data->ants;
	ft_print_map(data->map);
	if (paths->nb_mv == 2 && paths->path[1] == data->end->index &&
			paths->path[0] == data->start->index)
		return (ft_put_in_end(paths, data));
	while (data->end->ant_on < data->ants)
	{
		if (data->start->ant_on != data->ants)
		{
			ft_mv_ant(paths, data);
			ft_print_mv_ant(data->begin_list, paths);
		}
		if (data->start->ant_on > 0)
		{
			to_push_st = ft_put_in_rooms(paths, data->start->ant_on);
			ft_print_st(to_push_st, paths, data->begin_list, &pushed);
		}
		data->start->ant_on -= to_push_st;
		ft_printf("\n");
	}
	ft_print_error(NULL, data, paths);
}
