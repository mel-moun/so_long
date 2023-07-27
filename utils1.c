/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:36:11 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/24 13:36:27 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_putnbr_fd(int n)
{
	long	i;

	i = n;
	if (i < 0)
	{
		write (1, "-", 1);
		i = i * (-1);
	}
	if (i >= 0 && i <= 9)
		ft_putchar_fd(i + 48);
	else
	{
		ft_putnbr_fd(i / 10);
		ft_putnbr_fd(i % 10);
	}
}

void	ft_putchar_fd(char c)
{
	write (1, &c, 1);
}
