/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:08:52 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/25 12:57:21 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*reading_map(char *file, t_map *all)
{
	int		fd;
	char	*re;

	if (ft_strncmp(file + strlenn(file) - 3, "ber", 3) != 0)
	{
		write(2, "Error\nFile's name must be .ber", 30);
		exit (1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nOpening file");
		exit (1);
	}
	all->line = get_next_line(fd);
	re = NULL;
	while (all->line)
	{
		re = ft_strjoin(re, all->line);
		free(all->line);
		all->line = get_next_line(fd);
	}
	return (re);
}

int	newline(t_map *all)
{
	int	i;

	i = 0;
	if (all->line[i] == '\n')
		return (1);
	while (all->line[i])
	{
		if (all->line[i] == '\n' && all->line[i + 1] == '\n')
			return (1);
		i++;
	}
	if (all->line[i - 1] == '\n')
		return (1);
	return (0);
}

int	characters(t_map *all)
{
	int		i;

	i = 0;
	all->start = 0;
	all->collec = 0;
	all->quite = 0;
	if (newline(all) == 1)
		return (0);
	while (all->line[i])
	{
		if (all->line[i] == 'P')
			all->start++;
		else if (all->line[i] == 'C')
			all->collec++;
		else if (all->line[i] == 'E')
			all->quite++;
		else if (all->line[i] != 'P' && all->line[i] != 'C' \
		&& all->line[i] != 'E' && all->line[i] != '0' \
		&& all->line[i] != '1' && all->line[i] != '\n')
			return (0);
		i++;
	}
	if (all->quite == 1 && all->collec >= 1 && all->start == 1)
		return (1);
	return (0);
}

int	validlength(t_map *all)
{
	int	i;
	int	len;

	i = 0;
	if (!all->map)
		return (0);
	len = strlenn(all->map[i]);
	while (all->map[i])
	{
		if (strlenn(all->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	surronded(t_map *all)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	all->wid = 0;
	while (all->map[++i])
		all->wid++;
	all->len = strlenn(all->map[0]);
	i = -1;
	while (all->map[++i])
	{
		if (i == 0 || i == all->wid - 1)
		{
			while (all->map[i][++j])
			{
				if (all->map[i][j] != '1')
					return (0);
			}
			j = -1;
		}
		if (all->map[i][0] != '1' || all->map[i][all->len - 1] != '1')
			return (0);
	}
	return (1);
}
