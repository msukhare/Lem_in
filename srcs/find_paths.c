/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 09:38:06 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/10 10:39:13 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_init_path(int *path, int start, int size)
{
	int			i;

	path[0] = start;
	i = 1;
	while (i < size)
	{
		path[i] = -1;
		i++;
	}
}

static t_path	*ft_creat_new_path(int *path, int size_max)
{
	t_path		*new;
	int			i;

	i = 0;
	if (!(new = (t_path *)malloc(sizeof(t_path) * 1)))
		return (NULL);
	new->nb_mv = 0;
	while (new->nb_mv < size_max && path[new->nb_mv] != -1)
		new->nb_mv++;
	if (!(new->path = (int *)malloc(sizeof(int) * new->nb_mv)))
	{
		free(new);
		return (NULL);
	}
	i = 0;
	while (i < new->nb_mv)
	{
		new->path[i] = path[i];
		i++;
	}
	new->next = NULL;
	return (new);
}

static void		ft_creat_path(t_path **paths, int *path, t_lem_in *data)
{
	t_path		*tmp;

	if (!(*paths))
	{
		if (!(*paths = ft_creat_new_path(path, data->nb_rooms)))
		{
			ft_print_error("malloc fail\n", data, *paths);
			exit(-1);
		}
	}
	else
	{
		tmp = *paths;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_creat_new_path(path, data->nb_rooms)))
		{
			ft_print_error("malloc fail\n", data, *paths);
			exit(-1);
		}
	}
}

void			ft_find_paths(t_lem_in *data)
{
	t_path		*paths;
	int			*path;

	paths = NULL;
	if (!(path = (int*)malloc(sizeof(int) * data->nb_rooms)))
	{
		ft_print_error("malloc fail\n", data, paths);
		exit(-1);
	}
	ft_init_path(path, data->start->index, data->nb_rooms);
	while (ft_get_path(data, paths, path, data->start->index) > 0)
	{
		ft_creat_path(&paths, path, data);
		ft_init_path(path, data->start->index, data->nb_rooms);
	}
	if (paths)
	{
		ft_sort(paths);
		ft_clean_path(paths);
		ft_push_ant(data, paths);
	}
	else
		ft_print_error("ERROR\n", data, paths);
	free(path);
}
