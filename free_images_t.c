/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:51:22 by mel-moun          #+#    #+#             */
/*   Updated: 2023/07/28 17:08:52 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_six(t_map *all)
{
	free_map(all);
	mlx_delete_texture(all->coin);
	mlx_delete_image(all->mlx, all->coin1);
	mlx_delete_texture(all->exit);
	mlx_delete_image(all->mlx, all->exit1);
	mlx_delete_texture(all->free);
	exit(1);
}

void	free_seven(t_map *all)
{
	free_map(all);
	mlx_delete_texture(all->coin);
	mlx_delete_image(all->mlx, all->coin1);
	mlx_delete_texture(all->exit);
	mlx_delete_image(all->mlx, all->exit1);
	mlx_delete_texture(all->free);
	mlx_delete_image(all->mlx, all->free1);
	exit(1);
}

void	free_eight(t_map *all)
{
	free_map(all);
	mlx_delete_texture(all->coin);
	mlx_delete_image(all->mlx, all->coin1);
	mlx_delete_texture(all->exit);
	mlx_delete_image(all->mlx, all->exit1);
	mlx_delete_texture(all->free);
	mlx_delete_image(all->mlx, all->free1);
	mlx_delete_texture(all->wall);
	exit(1);
}

void	free_nine(t_map *all)
{
	free_map(all);
	mlx_delete_texture(all->coin);
	mlx_delete_image(all->mlx, all->coin1);
	mlx_delete_texture(all->exit);
	mlx_delete_image(all->mlx, all->exit1);
	mlx_delete_texture(all->free);
	mlx_delete_image(all->mlx, all->free1);
	mlx_delete_texture(all->wall);
	mlx_delete_image(all->mlx, all->wall1);
	exit(1);
}

void	free_ten(t_map *all)
{
	free_map(all);
	mlx_delete_texture(all->coin);
	mlx_delete_image(all->mlx, all->coin1);
	mlx_delete_texture(all->exit);
	mlx_delete_image(all->mlx, all->exit1);
	mlx_delete_texture(all->free);
	mlx_delete_image(all->mlx, all->free1);
	mlx_delete_texture(all->wall);
	mlx_delete_image(all->mlx, all->wall1);
	mlx_delete_texture(all->player);
	exit(1);
}
