/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukhare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 12:09:45 by msukhare          #+#    #+#             */
/*   Updated: 2018/05/10 14:12:10 by msukhare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*ft_read_hash(t_lem_in *data)
{
	char	*to_ret;

	to_ret = NULL;
	while (get_next_line(0, &to_ret) > 0 && to_ret[0] == '#')
	{
		if (ft_strcmp(to_ret, "##end") == 0 ||
				ft_strcmp(to_ret, "##start") == 0)
		{
			free(to_ret);
			return (NULL);
		}
		ft_push_line_back(data, to_ret);
	}
	return (to_ret);
}

static int	ft_get_st_or_end(t_lem_in *data, char *line)
{
	char	*tmp;
	t_rooms	*new;

	tmp = NULL;
	ft_push_line_back(data, line);
	if (!(tmp = ft_read_hash(data)))
		return (0);
	if (ft_checkrooms(tmp, data) == 0)
	{
		free(tmp);
		return (0);
	}
	new = ft_creatroom(tmp, data);
	if (ft_strcmp("##start", line) == 0)
		data->start = new;
	else
		data->end = new;
	ft_push_in_lst(new, data);
	ft_push_line_back(data, tmp);
	return (1);
}

static int	ft_all_digit(char *line)
{
	int		i;

	i = 0;
	if (line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (!(line[i] >= '0' && line[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_checkline(char *line, int type, t_lem_in *data)
{
	if (ft_all_digit(line) && data->ants == 0 && type <= 1)
	{
		ft_push_line_back(data, line);
		return (1);
	}
	else if (ft_checkrooms(line, data) && type <= 2 && data->ants > 0)
	{
		ft_push_line_back(data, line);
		return (2);
	}
	else if (ft_check_connect(line, data) && type <= 3 && data->ants > 0)
	{
		ft_push_line_back(data, line);
		return (3);
	}
	return (0);
}

void		ft_read_file(t_lem_in *data)
{
	char	*line;
	int		type;

	line = NULL;
	type = 1;
	while ((get_next_line(0, &line)) > 0)
	{
		if (line[0] == '#' && type <= 2 && ((!data->start &&
			ft_strcmp("##start", line) == 0) || (!data->end &&
			ft_strcmp("##end", line) == 0)))
		{
			if (ft_get_st_or_end(data, line) == 0)
				return ;
		}
		else if (line[0] != '#' && (type = ft_checkline(line, type, data)) > 0)
			ft_getinfo(line, type, data);
		else if (line[0] != '#' || ft_strcmp("##end", line) == 0 ||
			ft_strcmp("##start", line) == 0)
			return (free(line));
		else
			ft_push_line_back(data, line);
	}
	free(line);
}
