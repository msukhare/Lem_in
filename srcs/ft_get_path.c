/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 08:56:31 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/04 09:56:49 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check_path(int *path, int to_check, int size)
{
	int		i;

	i = 0;
	while (i < size && path[i] != -1)
	{
		if (path[i] == to_check)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_in_paths(t_path *paths, int *path)
{
	int		i;

	if (!paths)
		return (1);
	while (paths)
	{
		i = 0;
		while (i < paths->nb_mv && path[i] == paths->path[i])
			i++;
		if (i == paths->nb_mv)
			return (0);
		paths = paths->next;
	}
	return (1);
}

int			ft_get_path(t_lem_in *data, t_path *paths, int *path, int start)
{
	int		i;
	int		j;

	if (start == data->end->index && ft_check_in_paths(paths, path))
		return (1);
	else if (start == data->end->index)
		return (0);
	i = 0;
	while (i < data->nb_rooms)
	{
		if (data->mat_co[start][i] != 0 &&
				ft_check_path(path, i, data->nb_rooms))
		{
			j = 0;
			while (path[j] != -1 && j < data->nb_rooms)
				j++;
			path[j] = i;
			if (ft_get_path(data, paths, path, i) > 0)
				return (1);
			path[j] = -1;
		}
		i++;
	}
	return (0);
}
