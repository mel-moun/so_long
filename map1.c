/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:34:56 by mel-moun          #+#    #+#             */
/*   Updated: 2023/07/28 19:46:04 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	coordinates(t_map *all)
{
	int	i;
	int	j;

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
				free_map(all);
				free_fakemap(all);
				exit (1);
			}
		}
		j = -1;
	}
	free_fakemap(all);
}

void	split_map(t_map *all)
{
	all->map = ft_split(all->line, '\n');
	if (!all->map)
	{
		free(all->line);
		exit (1);
	}
	all->fmap = ft_split(all->line, '\n');
	if (!all->fmap)
	{
		free(all->line);
		free_map(all);
		exit (1);
	}
}

void	ismapvalid(t_map *all, char *file)
{
	all->line = reading_map(file, all);
	if (!all->line)
	{
		write(2, "Error\nCan you write a map ?\n", 28);
		exit (1);
	}
	split_map(all);
	if (newline(all) || !characters(all) || !validlength(all))
		error_msg(all);
	free(all->line);
	if (!surronded(all))
		error_msg(all);
	coordinates(all);
	backtracking(all->xt, all->yt, all);
	validpath(all);
}
