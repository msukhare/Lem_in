/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:35:58 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/04 12:52:00 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_swap_links(t_path *swap, t_path *lst)
{
	int		*tmp;
	int		tmp2;

	tmp2 = swap->nb_mv;
	swap->nb_mv = lst->nb_mv;
	lst->nb_mv = tmp2;
	tmp = swap->path;
	swap->path = lst->path;
	lst->path = tmp;
}

void		ft_sort(t_path *path)
{
	t_path	*tmp;
	t_path	*swap;

	while (path)
	{
		tmp = path;
		swap = path;
		while (tmp)
		{
			if (tmp->nb_mv < swap->nb_mv)
				swap = tmp;
			tmp = tmp->next;
		}
		ft_swap_links(swap, path);
		path = path->next;
	}
}
