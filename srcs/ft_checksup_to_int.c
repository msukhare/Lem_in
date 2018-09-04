/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checksup_to_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 14:02:36 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/09 14:48:56 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_checksup_to_int(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	(line[i] && line[i] == ' ') ? i++ : 0;
	j = 0;
	while (line[i] && line[i] != ' ')
	{
		j++;
		i++;
	}
	(line[i] && line[i] == ' ') ? i++ : 0;
	if (j >= 12)
		return (1);
	j = 0;
	while (line[i] && line[i] != ' ')
	{
		j++;
		i++;
	}
	if (j >= 12)
		return (1);
	return (0);
}
