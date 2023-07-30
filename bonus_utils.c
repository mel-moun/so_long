/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:10:08 by mel-moun          #+#    #+#             */
/*   Updated: 2023/07/28 20:17:26 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	mouvements_bonus(int x, int y, t_map *all)
{
	static int	i;
	char		*itoad;

	all->x += x;
	all->y += y;
	check(all, all->wall1, 0, 0);
	all->bonus = mlx_put_string(all->mlx, "move:", 1, 1);
	if (!all->bonus)
		mlx_close_window(all->mlx);
	++i;
	itoad = ft_itoa(i);
	all->bonus = mlx_put_string(all->mlx, itoad, 50, 1);
	if (!all->bonus)
		mlx_close_window(all->mlx);
	free(itoad);
	mlx_delete_image(all->mlx, all->player1);
	all->player1 = mlx_texture_to_image(all->mlx, all->player);
	if (!all->player1)
		mlx_close_window(all->mlx);
	check(all, all->player1, all->x, all->y);
	collectibales(all, x, y);
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
