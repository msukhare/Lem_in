/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:52:48 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/04 13:48:25 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_if_same_room(t_path *tmp, t_path *path)
{
	int		i;
	int		j;

	i = 1;
	while (i < (path->nb_mv - 1))
	{
		j = 1;
		while (j < (tmp->nb_mv - 1))
		{
			if (path->path[i] == tmp->path[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void		ft_clean_path(t_path *paths)
{
	t_path	*tmp;
	t_path	*to_del;

	while (paths)
	{
		to_del = paths->next;
		while (to_del)
		{
			if (ft_if_same_room(to_del, paths))
			{
				tmp = paths;
				while (tmp && tmp->next != to_del)
					tmp = tmp->next;
				tmp->next = to_del->next;
				free(to_del->path);
				free(to_del);
				to_del = tmp;
			}
			to_del = to_del->next;
		}
		paths = paths->next;
	}
}
