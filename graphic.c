/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:57:58 by mel-moun          #+#    #+#             */
/*   Updated: 2023/07/28 19:41:52 by mel-moun         ###   ########.fr       */
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

void	check(t_map *all, mlx_image_t *img, int i, int j)
{
	if (mlx_image_to_window(all->mlx, img, i, j) < 0)
	{
		perror("Error\n");
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
