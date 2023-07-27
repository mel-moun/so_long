/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:38:55 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/30 12:43:35 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	validmax(t_map *all)
{
	int	i;

	i = 0;
	if (all->length > 29 || all->width > 16)
	{
		write (2, "Error\nInvalid length or width", 29);
		while (all->map[i])
			free(all->map[i++]);
		free(all->map);
		exit (1);
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
			exit(1);
		printmap(all.map, &all);
		coordinates(&all);
		mlx_loop_hook(all.mlx, &my_keyhook, &all);
		mlx_loop(all.mlx);
		mlx_terminate(all.mlx);
	}
	else
		write(2, "Error\nCan you give us a map?", 27);
	return (0);
}
