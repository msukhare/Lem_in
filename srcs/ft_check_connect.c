/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_connect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 10:46:52 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/09 15:55:29 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_check_matrice(t_lem_in *data, char *line)
{
	t_rooms	*tmp;

	tmp = data->begin_list;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, line, ft_strclen(line, '-')) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	ft_check_double_liai(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '-')
		i++;
	(str[i] == '-') ? i++ : 0;
	while (str[i] && str[j] && str[j] != '-' && str[i] == str[j])
	{
		i++;
		j++;
	}
	if (str[i] == '\0' && str[j] == '-')
		return (1);
	return (0);
}

int			ft_check_connect(char *line, t_lem_in *data)
{
	int		i;
	int		sep;

	i = 0;
	sep = 0;
	if (line[i] == '\0' || line[i] == 'L' || line[i] == '-')
		return (0);
	while (line[i])
	{
		if (line[i] == '-')
			sep++;
		else if (line[i] == ' ' || line[i] == '\t')
			return (0);
		i++;
	}
	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	(line[i] == '-') ? i++ : 0;
	if (sep != 1 || line[i] == '\0' || ft_check_double_liai(line) ||
		ft_check_matrice(data, line) == 0 ||
			ft_check_matrice(data, (line + i)) == 0)
		return (0);
	return (1);
}
