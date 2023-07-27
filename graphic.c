/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:57:58 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/30 12:29:49 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	length(t_map *all, char **map)
{
	int	i;

	i = 0;
	all->length = strlenn(map[0]);
	while (map[i])
		i++;
	all->width = i;
}

void	loadimages(t_map *all)
{
	all->coin = mlx_load_png("images/coin.png");
	all->exit = mlx_load_png("images/exit.png");
	all->free = mlx_load_png("images/free.png");
	all->wall = mlx_load_png("images/wall.png");
	all->player = mlx_load_png("images/player.png");
	if (!all->coin || !all->exit || !all->free || !all->wall || !all->player)
	{
		perror("Error\n");
		exit(1);
	}
	all->player1 = mlx_texture_to_image(all->mlx, all->player);
	all->coin1 = mlx_texture_to_image(all->mlx, all->coin);
	all->exit1 = mlx_texture_to_image(all->mlx, all->exit);
	all->free1 = mlx_texture_to_image(all->mlx, all->free);
	all->wall1 = mlx_texture_to_image(all->mlx, all->wall);
	if (!all->coin1 || !all->player1 || !all->exit1 \
	|| !all->free1 || !all->wall1)
	{
		perror("Error\n");
		exit(1);
	}
}

void	check(t_map *all, mlx_image_t *img, int i, int j)
{
	if (mlx_image_to_window(all->mlx, img, i, j) < 0)
	{
		perror("Error\n");
		i = 0;
		while (all->map[i++])
			free(all->map[i]);
		free(all->map);
		mlx_close_window(all->mlx);
	}
}

void	change(t_map *all, int i, int j)
{
	all->x = i * 90;
	all->y = j * 90;
}

void	printmap(char **map, t_map *all)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	loadimages(all);
	while (map[++j])
	{
		while (map[j][++i])
		{
			if (map[j][i] == 'C')
				check(all, all->coin1, i * 90, j * 90);
			else if (map[j][i] == 'E')
				check(all, all->exit1, i * 90, j * 90);
			else if (map[j][i] == '0')
				check(all, all->free1, i * 90, j * 90);
			else if (map[j][i] == '1')
				check(all, all->wall1, i * 90, j * 90);
			else if (map[j][i] == 'P')
				change(all, i, j);
		}
		i = -1;
	}
	check(all, all->free1, all->x, all->y);
	check(all, all->player1, all->x, all->y);
}
