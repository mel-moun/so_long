/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:34:45 by mel-moun          #+#    #+#             */
/*   Updated: 2023/07/28 15:59:47 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	strlenn(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*p;
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (start >= strlenn(s))
		return (ft_calloc(1, 1));
	if (len >= strlenn(s) - start)
		return (ft_strdup(s + start));
	p = (char *) malloc(len * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	while (i < len && start <= strlenn(s))
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *) malloc (strlenn(s1) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	while (i < n && (ss2[i] != '\0' || ss1[i] != '\0'))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

void	mouvements(int x, int y, t_map *all)
{
	static int	num;

	all->x += x;
	all->y += y;
	++num;
	ft_putnbr_fd(num);
	ft_putchar_fd('\n');
	mlx_delete_image(all->mlx, all->player1);
	all->player1 = mlx_texture_to_image(all->mlx, all->player);
	if (!all->player1)
	{
		free_map(all);
		mlx_close_window(all->mlx);
	}
	check(all, all->player1, all->x, all->y);
	collectibales(all, x, y);
}
