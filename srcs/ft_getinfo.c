/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:40:18 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/09 10:12:30 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_init_tab(int **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

static int	**ft_creat_tab(t_lem_in *data)
{
	int		**to_ret;
	int		size;
	int		i;

	i = 0;
	size = ft_lenlst(data->begin_list);
	if (!(to_ret = (int **)malloc(sizeof(int *) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(to_ret[i] = (int*)malloc(sizeof(int) * size)))
		{
			ft_free_tab(to_ret, i);
			return (NULL);
		}
		i++;
	}
	ft_init_tab(to_ret, size);
	return (to_ret);
}

static int	ft_index(char *line, t_lem_in *data)
{
	t_rooms	*tmp;
	int		i;

	tmp = data->begin_list;
	while (tmp)
	{
		i = 0;
		while (line[i] && line[i] != '-' && tmp->name[i] != '\0' &&
				line[i] == tmp->name[i])
			i++;
		if (tmp->name[i] == '\0' && (line[i] == '-' || line[i] == '\0'))
			return (tmp->index);
		tmp = tmp->next;
	}
	return (0);
}

static void	ft_get_co(t_lem_in *data, char *line)
{
	int		size;

	if (!(data->mat_co))
	{
		if (!(data->mat_co = ft_creat_tab(data)))
		{
			free(line);
			ft_print_error("malloc fail\n", data, NULL);
			exit(-1);
		}
	}
	size = ft_strclen(line, '-');
	if (line[size] == '-')
		size++;
	data->mat_co[ft_index(line, data)][ft_index((line + size), data)] = 1;
	data->mat_co[ft_index((line + size), data)][ft_index(line, data)] = 1;
}

void		ft_getinfo(char *line, int type, t_lem_in *data)
{
	t_rooms	*room;

	if (type == 1)
		data->ants = ft_atoi(line);
	else if (type == 2)
	{
		room = ft_creatroom(line, data);
		ft_push_in_lst(room, data);
	}
	else if (type == 3)
		ft_get_co(data, line);
}
