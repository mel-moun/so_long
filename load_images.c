/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:07:19 by mel-moun          #+#    #+#             */
/*   Updated: 2023/07/28 17:07:53 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	load_images(t_map *all)
{
	if (!all->free1)
		free_six(all);
	all->wall = mlx_load_png("images/wall.png");
	if (!all->wall)
		free_seven(all);
	all->wall1 = mlx_texture_to_image(all->mlx, all->wall);
	if (!all->wall1)
		free_eight(all);
	all->player = mlx_load_png("images/player.png");
	if (!all->player)
		free_nine(all);
	all->player1 = mlx_texture_to_image(all->mlx, all->player);
	if (!all->player1)
		free_ten(all);
}

void	loadimages(t_map *all)
{
	all->coin = mlx_load_png("images/coin.png");
	if (!all->coin)
		free_one(all);
	all->coin1 = mlx_texture_to_image(all->mlx, all->coin);
	if (!all->coin1)
		free_two(all);
	all->exit = mlx_load_png("images/exit.png");
	if (!all->exit)
		free_three(all);
	all->exit1 = mlx_texture_to_image(all->mlx, all->exit);
	if (!all->exit1)
		free_four(all);
	all->free = mlx_load_png("images/free.png");
	if (!all->free)
		free_five(all);
	all->free1 = mlx_texture_to_image(all->mlx, all->free);
	load_images(all);
}
