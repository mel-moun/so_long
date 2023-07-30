/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:38:55 by mel-moun          #+#    #+#             */
/*   Updated: 2023/07/28 20:20:16 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	validmax(t_map *all)
{
	if (all->length > 29 || all->width > 16)
	{
		write (2, "Error\nInvalid length or width", 29);
		free_map(all);
		exit (1);
	}
}

void	free_fakemap(t_map *all)
{
	int	i;

	i = 0;
	while (all->fmap[i])
	{
		free(all->fmap[i]);
		i++;
	}
	free(all->fmap);
}

void	free_map(t_map *all)
{
	int	i;

	i = 0;
	if (all->map)
	{
		while (all->map[i])
		{
			free(all->map[i]);
			i++;
		}
		free(all->map);
	}
}

int	main(int ac, char **av)
{
	t_map	all;

	if (ac == 2)
	{
		ismapvalid(&all, av[1]);
		length(&all, all.map);
		validmax(&all);
		all.mlx = mlx_init(all.length * 90, all.width * 90, "./so_long", false);
		if (!all.mlx)
		{
			free_map(&all);
			exit(1);
		}
		printmap(all.map, &all);
		coordinates(&all);
		mlx_key_hook(all.mlx, &my_keyhook, &all);
		mlx_loop(all.mlx);
		free_map(&all);
		mlx_terminate(all.mlx);
		return (0);
	}
	write(2, "Error\nCan you give us a map?", 27);
	return (1);
}
