/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:24:37 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/30 12:41:47 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	count(t_map *all)
{
	static int	i;
	char		*itoad;
	int			x;
	int			y;

	x = all->x - all->xt;
	y = all->y - all->yt;
	if (x >= 90 || x <= -90 || y >= 90 || y <= -90)
	{
		all->xt = all->x;
		all->yt = all->y;
		check(all, all->wall1, 0, 0);
		mlx_put_string(all->mlx, "move:", 1, 1);
		itoad = ft_itoa(i);
		mlx_put_string(all->mlx, itoad, 50, 1);
		free(itoad);
		i++;
	}
}

static int	lengggth(int n)
{
	long	i;
	long	count;

	i = n;
	count = 0;
	if (i < 0)
	{
		i = i * (-1);
		count++;
	}
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i = i / 10;
		count++;
	}
	return (count);
}

static char	*kteb(char *p, long len, long bo, long i)
{
	while (len >= bo)
	{
		p[len] = i % 10 + 48;
		i = i / 10;
		len--;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	long	i;
	int		len;
	char	*p;
	int		bo;

	i = n;
	bo = 0;
	len = lengggth(i);
	p = (char *) malloc (len + 1);
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	if (i < 0)
	{
		bo = 1;
		i = i * (-1);
		p[0] = '-';
	}
	len--;
	return (kteb(p, len, bo, i));
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
	count(all);
}
