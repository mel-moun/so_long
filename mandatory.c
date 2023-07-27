/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   madatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:32:41 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/24 13:54:50 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	madatory(t_map *all)
{
	static int	num;
	int			x;
	int			y;

	x = all->x - all->xt;
	y = all->y - all->yt;
	if (x >= 90 || x <= -90 || y >= 90 || y <= -90)
	{
		all->xt = all->x;
		all->yt = all->y;
		ft_putnbr_fd(num);
		ft_putchar_fd('\n');
		num++;
	}
}

void	my_keyhook(void *param)
{
	t_map	*all;

	all = param;
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(all->mlx);
	else if (mlx_is_key_down(all->mlx, MLX_KEY_UP) && check_step(0, -10, all))
		mouvements(0, -10, all);
	else if (mlx_is_key_down(all->mlx, MLX_KEY_DOWN) && check_step(0, 10, all))
		mouvements(0, 10, all);
	else if (mlx_is_key_down(all->mlx, MLX_KEY_LEFT) && check_step(-10, 0, all))
		mouvements(-10, 0, all);
	else if (mlx_is_key_down(all->mlx, MLX_KEY_RIGHT) && check_step(10, 0, all))
		mouvements(10, 0, all);
	madatory(all);
}
