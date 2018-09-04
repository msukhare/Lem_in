/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 11:58:03 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/10 10:38:20 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				main(void)
{
	t_lem_in	data;

	data.ants = 0;
	data.begin_list = NULL;
	data.start = NULL;
	data.end = NULL;
	data.mat_co = NULL;
	data.map = NULL;
	ft_read_file(&data);
	if (data.ants <= 0 || !data.begin_list || !data.mat_co || !data.start ||
			!data.end)
	{
		ft_print_error("ERROR\n", &data, NULL);
		return (0);
	}
	data.nb_rooms = ft_lenlst(data.begin_list);
	ft_find_paths(&data);
	return (0);
}
