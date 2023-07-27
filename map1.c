/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:34:56 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/30 12:09:31 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	coordinates(t_map *all)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (all->map[j])
	{
		while (all->map[j][i])
		{
			if (all->map[j][i] == 'P')
			{
				all->xt = i;
				all->yt = j;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void	backtracking(int xt, int yt, t_map *all)
{
	if (all->fmap[yt - 1][xt] != '1')
	{
		all->fmap[yt - 1][xt] = '1';
		backtracking(xt, yt - 1, all);
	}
	if (all->fmap[yt + 1][xt] != '1')
	{
		all->fmap[yt + 1][xt] = '1';
		backtracking(xt, yt + 1, all);
	}
	if (all->fmap[yt][xt - 1] != '1')
	{
		all->fmap[yt][xt - 1] = '1';
		backtracking(xt - 1, yt, all);
	}
	if (all->fmap[yt][xt + 1] != '1')
	{
		all->fmap[yt][xt + 1] = '1';
		backtracking(xt + 1, yt, all);
	}
}

void	validpath(t_map *all)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (all->fmap[++i])
	{
		while (all->fmap[i][++j])
		{
			if (all->fmap[i][j] != '1' && all->fmap[i][j] != '0')
			{
				write(2, "Error\nInvalid path\n", 19);
				i = -1;
				while (all->fmap[++i])
					free(all->fmap[i]);
				free(all->fmap);
				exit (1);
			}
		}
		j = -1;
	}
	i = -1;
	while (all->fmap[++i])
		free(all->fmap[i]);
	free(all->fmap);
}

void	error_msg(t_map *all)
{
	int	i;

	i = 0;
	write (2, "Error\nInvalid map\n", 18);
	while (all->map[i])
	{
		free(all->map[i]);
		i++;
	}
	free(all->map);
	i = 0;
	while (all->fmap[i])
	{
		free(all->fmap[i]);
		i++;
	}
	free(all->fmap);
	exit (1);
}

void	ismapvalid(t_map *all, char *file)
{
	all->line = reading_map(file, all);
	if (!all->line)
	{
		write(2, "Error\nCan you write a map ?\n", 28);
		exit (1);
	}
	all->map = ft_split(all->line, '\n');
	all->fmap = ft_split(all->line, '\n');
	if (!all->map || !all->fmap)
		exit (1);
	if (newline(all) == 1 || characters(all) == 0 || validlength(all) == 0)
		error_msg(all);
	if (surronded(all) == 0)
		error_msg(all);
	coordinates(all);
	backtracking(all->xt, all->yt, all);
	validpath(all);
}