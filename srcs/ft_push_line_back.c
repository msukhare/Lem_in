/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_line_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 09:45:43 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/09 10:15:14 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_map	*ft_creat_line(char *line)
{
	t_map		*new_line;

	if (!(new_line = (t_map*)malloc(sizeof(t_map) * 1)))
	{
		free(line);
		return (NULL);
	}
	new_line->next = NULL;
	new_line->line = line;
	return (new_line);
}

void			ft_push_line_back(t_lem_in *data, char *line)
{
	t_map		*tmp;

	if (!data->map)
	{
		if (!(data->map = ft_creat_line(line)))
		{
			ft_print_error("malloc fail\n", data, NULL);
			exit(-1);
		}
	}
	else
	{
		tmp = data->map;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_creat_line(line)))
		{
			ft_print_error("malloc fail\n", data, NULL);
			exit(-1);
		}
	}
}
