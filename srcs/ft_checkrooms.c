/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkrooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 09:20:28 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/09 14:04:37 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_count_c(char *line, char c)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			nb++;
		i++;
	}
	return (nb);
}

static int	ft_check_str_to_c(char *line, char to_check, char c)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != c)
	{
		if (line[i] == to_check)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_signe(char *line, int i)
{
	if ((i > 1 && line[i - 1] != ' ') ||
			!(line[i + 1] >= '0' && line[i + 1] <= '9'))
		return (1);
	if (line[i] == '+' || line[i] == '-')
		i++;
	while (line[i] && line[i] != ' ')
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_double_rooms(char *line, t_lem_in *data)
{
	t_rooms	*tmp;
	int		i;
	long	x;
	long	y;

	tmp = data->begin_list;
	while (tmp)
	{
		i = 0;
		if (ft_strccmp(tmp->name, line, ' ') == 0)
			return (1);
		while (line[i] && line[i] != ' ')
			i++;
		(line[i] == ' ') ? i++ : 0;
		x = ft_atol(line + i);
		while (line[i] && line[i] != ' ')
			i++;
		y = ft_atol(line + i);
		if ((x == tmp->x && y == tmp->y) || x > 2147483647 || x < -2147483648 ||
				y > 2147483647 || y < -2147483648)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_checkrooms(char *line, t_lem_in *data)
{
	int		i;

	i = 0;
	if (line[0] == '#' || line[0] == 'L')
		return (0);
	if (ft_count_c(line, ' ') != 2 || ft_check_str_to_c(line, '-', ' '))
		return (0);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i])
	{
		if ((line[i] == '+' || line[i] == '-') && ft_check_signe(line, i))
			return (0);
		if (!(line[i] >= '0' && line[i] <= '9') && line[i] != ' ' &&
				line[i] != '+' && line[i] != '-')
			return (0);
		if (line[i] == ' ' && line[i + 1] == '\0')
			return (0);
		i++;
	}
	if ((data->begin_list && ft_check_double_rooms(line, data)) ||
			ft_checksup_to_int(line))
		return (0);
	return (1);
}
