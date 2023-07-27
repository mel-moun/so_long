/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:57:51 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/24 14:34:42 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	*ft_calloc(int count, int size)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *) malloc (count * size);
	if (p == NULL)
		return (NULL);
	while (i < (count * size))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	int			r;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (0);
	r = 1;
	while (r > 0 && checknl(buff) == 0)
	{
		r = read (fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(save);
			save = NULL;
			return (NULL);
		}
		buff[r] = '\0';
		save = ft_strjoin(save, buff);
	}
	if (!save)
		return (NULL);
	line = beforenl(save);
	save = afternl(save);
	return (line);
}
