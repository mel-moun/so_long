/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:30:41 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/30 12:32:46 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	exitposition(t_map *all, int x, int y)
{
	if (all->map[(all->y + y) / 90][(all->x + x) / 90] == 'E'\
	|| all->map[(all->y + 89 + y) / 90][(all->x + 89 + x) / 90] == 'E'\
	|| all->map[(all->y + 89 + y) / 90][(all->x + x) / 90] == 'E'\
	|| all->map[(all->y + y) / 90][(all->x + 89 + x) / 90] == 'E')
		return (1);
	return (0);
}

void	coor(t_map *all, int x, int y)
{
	int	i;

	if (mlx_image_to_window(all->mlx, all->free1, x, y) < 0)
	{
		perror("Error\n");
		i = 0;
		while (all->map[i++])
			free(all->map[i]);
		free(all->map);
		mlx_close_window(all->mlx);
	}
}

void	allcollec(t_map *all, int x, int y)
{
	if (all->collec == 0 && exitposition(all, x, y))
		mlx_close_window(all->mlx);
}

void	collectibales(t_map *all, int x, int y)
{
	if (all->map[(all->y + y) / 90][(all->x + x) / 90] == 'C')
	{
		all->map[(all->y + y) / 90][(all->x + x) / 90] = '0';
		all->collec--;
		coor(all, (all->x + x) / 90 * 90, (all->y + y) / 90 * 90);
	}
	else if (all->map[(all->y + 89 + y) / 90][(all->x + 89 + x) / 90] == 'C')
	{
		all->map[(all->y + 89 + y) / 90][(all->x + 89 + x) / 90] = '0';
		all->collec--;
		coor(all, (all->x + 89 + x) / 90 * 90, (all->y + 89 + y) / 90 * 90);
	}
	else if (all->map[(all->y + 89 + y) / 90][(all->x + x) / 90] == 'C')
	{
		all->map[(all->y + 89 + y) / 90][(all->x + x) / 90] = '0';
		all->collec--;
		coor(all, (all->x + x) / 90 * 90, (all->y + 89 + y) / 90 * 90);
	}
	else if (all->map[(all->y + y) / 90][(all->x + 89 + x) / 90] == 'C')
	{
		all->map[(all->y + y) / 90][(all->x + 89 + x) / 90] = '0';
		all->collec--;
		coor(all, (all->x + 89 + x) / 90 * 90, (all->y + y) / 90 * 90);
	}
	allcollec(all, x, y);
}

int	check_step(int x, int y, t_map *all)
{
	if (all->map[(all->y + y) / 90][(all->x + x) / 90] == '1')
		return (0);
	if (all->map[(all->y + 89 + y) / 90][(all->x + 89 + x) / 90] == '1')
		return (0);
	if (all->map[(all->y + 89 + y) / 90][(all->x + x) / 90] == '1')
		return (0);
	if (all->map[(all->y + y) / 90][(all->x + 89 + x) / 90] == '1')
		return (0);
	return (1);
}
