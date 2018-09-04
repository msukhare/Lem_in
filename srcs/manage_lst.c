/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:42:23 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/04 09:34:59 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*ft_alloc_name(char *line)
{
	char	*to_ret;
	int		to_cpy;
	int		i;

	to_cpy = ft_strclen(line, ' ');
	if (!(to_ret = (char*)malloc(sizeof(char) * (to_cpy + 1))))
		return (NULL);
	i = 0;
	while (i < to_cpy)
	{
		to_ret[i] = line[i];
		i++;
	}
	to_ret[i] = '\0';
	return (to_ret);
}

static int	ft_get_numb(char *line, int *i)
{
	while (line[*i] && line[*i] != ' ')
		(*i)++;
	if (line[*i] == ' ')
		(*i)++;
	return (ft_atoi(line + *i));
}

t_rooms		*ft_creatroom(char *line, t_lem_in *data)
{
	t_rooms		*to_ret;
	int			i;
	static int	ind;

	i = 0;
	if (!(to_ret = (t_rooms*)malloc(sizeof(t_rooms) * 1)))
	{
		ft_print_error("malloc fail\n", data, NULL);
		free(line);
		exit(-1);
	}
	if (!(to_ret->name = ft_alloc_name(line)))
	{
		free(to_ret);
		free(line);
		ft_print_error("malloc fail\n", data, NULL);
		exit(-1);
	}
	to_ret->x = ft_get_numb(line, &i);
	to_ret->y = ft_get_numb(line, &i);
	to_ret->next = NULL;
	to_ret->index = ind;
	ind++;
	to_ret->ant_on = 0;
	return (to_ret);
}

void		ft_push_in_lst(t_rooms *new_link, t_lem_in *data)
{
	t_rooms	*tmp;

	if (!data->begin_list)
		data->begin_list = new_link;
	else
	{
		tmp = data->begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_link;
	}
}

int			ft_lenlst(t_rooms *begin_list)
{
	int		size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}
