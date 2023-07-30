/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:55:44 by mel-moun          #+#    #+#             */
/*   Updated: 2023/07/28 17:08:18 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_one(t_map *all)
{
	free_map(all);
	exit(1);
}

void	free_two(t_map *all)
{
	free_map(all);
	mlx_delete_texture(all->coin);
	exit(1);
}

void	free_three(t_map *all)
{
	free_map(all);
	mlx_delete_texture(all->coin);
	mlx_delete_image(all->mlx, all->coin1);
	exit(1);
}

void	free_four(t_map *all)
{
	free_map(all);
	mlx_delete_texture(all->coin);
	mlx_delete_image(all->mlx, all->coin1);
	mlx_delete_texture(all->exit);
	exit(1);
}

void	free_five(t_map *all)
{
	free_map(all);
	mlx_delete_texture(all->coin);
	mlx_delete_image(all->mlx, all->coin1);
	mlx_delete_texture(all->exit);
	mlx_delete_image(all->mlx, all->exit1);
	exit(1);
}
