/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:24:37 by mel-moun          #+#    #+#             */
/*   Updated: 2023/07/28 17:02:30 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	left_right(mlx_key_data_t keydata, t_map *all)
{
	if (keydata.key == MLX_KEY_LEFT \
	&& keydata.action == MLX_PRESS && check_step(-15, 0, all))
		mouvements_bonus(-15, 0, all);
	else if (keydata.key == MLX_KEY_RIGHT \
	&& keydata.action == MLX_PRESS && check_step(15, 0, all))
		mouvements_bonus(15, 0, all);
	else if (keydata.key == MLX_KEY_LEFT \
	&& keydata.action == MLX_REPEAT && check_step(-15, 0, all))
		mouvements_bonus(-15, 0, all);
	else if (keydata.key == MLX_KEY_RIGHT \
	&& keydata.action == MLX_REPEAT && check_step(15, 0, all))
		mouvements_bonus(15, 0, all);
}

void	up_down(mlx_key_data_t keydata, t_map *all)
{
	if (keydata.key == MLX_KEY_UP \
	&& keydata.action == MLX_PRESS && check_step(0, -15, all))
		mouvements_bonus(0, -15, all);
	else if (keydata.key == MLX_KEY_UP \
	&& keydata.action == MLX_REPEAT && check_step(0, -15, all))
		mouvements_bonus(0, -15, all);
	else if (keydata.key == MLX_KEY_DOWN \
	&& keydata.action == MLX_PRESS && check_step(0, 15, all))
		mouvements_bonus(0, 15, all);
	else if (keydata.key == MLX_KEY_DOWN \
	&& keydata.action == MLX_REPEAT && check_step(0, 15, all))
		mouvements_bonus(0, 15, all);
}

void	my_keyhook(mlx_key_data_t data, void *param)
{
	t_map	*all;

	all = param;
	if (data.key == MLX_KEY_ESCAPE && data.action == MLX_PRESS)
		mlx_close_window(all->mlx);
	left_right(data, all);
	up_down(data, all);
}
