/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:19:54 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/04 09:34:38 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_free_map(t_map *map)
{
	t_map	*tmp;

	while (map)
	{
		tmp = map;
		map = map->next;
		free(tmp->line);
		free(tmp);
	}
}

void		ft_print_error(char *error, t_lem_in *data, t_path *path)
{
	t_rooms	*tmp;
	t_path	*tmp2;

	if (path)
	{
		while (path)
		{
			free(path->path);
			tmp2 = path;
			path = path->next;
			free(tmp2);
		}
	}
	ft_free_map(data->map);
	if (data->mat_co)
		ft_free_tab(data->mat_co, ft_lenlst(data->begin_list));
	while (data->begin_list)
	{
		tmp = data->begin_list;
		data->begin_list = data->begin_list->next;
		free(tmp->name);
		free(tmp);
	}
	if (error)
		ft_putstr_fd(error, 2);
}

void		ft_free_tab(int **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}
