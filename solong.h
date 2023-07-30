/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:36:57 by mel-moun          #+#    #+#             */
/*   Updated: 2023/07/28 20:16:19 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "/Users/mel-moun/goinfre/MLX/include/MLX42/MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_needs{
	int				x;
	int				xt;
	int				y;
	int				yt;
	int				len;
	int				wid;
	int				width;
	int				length;
	char			*line;
	char			**map;
	char			**fmap;
	int				quite;
	int				collec;
	int				start;
	mlx_t			*mlx;
	mlx_texture_t	*coin;
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_texture_t	*free;
	mlx_texture_t	*exit;
	mlx_image_t		*coin1;
	mlx_image_t		*player1;
	mlx_image_t		*wall1;
	mlx_image_t		*free1;
	mlx_image_t		*exit1;
	mlx_image_t		*bonus;
}	t_map;

char	**ft_split(char *s, char c);
int		ft_strlen(char *s, int j);
char	*ft_strjoin(char *s1, char *s2);
char	*beforenl(char *s);
char	*afternl(char *save);
int		checknl(char *p);
void	*ft_calloc(int count, int size);
char	*get_next_line(int fd);
int		exitposition(t_map *all, int x, int y);
void	coor(t_map *all, int x, int y);
void	collectibales(t_map *all, int x, int y);
void	mouvements(int x, int y, t_map *all);
int		check_step(int x, int y, t_map *all);
void	length(t_map *all, char **map);
void	loadimages(t_map *all);
void	check(t_map *all, mlx_image_t *img, int i, int j);
void	change(t_map *all, int i, int j);
void	printmap(char **map, t_map *all);
void	my_keyhook(mlx_key_data_t keydata, void *param);
char	*reading_map(char *file, t_map *all);
int		newline(t_map *all);
int		characters(t_map *all);
int		validlength(t_map *all);
int		surronded(t_map *all);
void	coordinates(t_map *all);
void	backtracking(int xplayer, int yplayer, t_map *all);
void	validpath(t_map *all);
void	error_msg(t_map *all);
void	ismapvalid(t_map *all, char *file);
char	*ft_itoa(int n);
int		strlenn(const char *s);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s1);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	ft_putnbr_fd(int n);
void	ft_putchar_fd(char c);
void	allcollec(t_map *all, int x, int y);
void	mouvements_bonus(int x, int y, t_map *all);
void	split_map(t_map *all);

//free
void	free_map(t_map *all);
void	free_fakemap(t_map *all);
void	free_one(t_map *all);
void	free_two(t_map *all);
void	free_three(t_map *all);
void	free_four(t_map *all);
void	free_five(t_map *all);
void	free_six(t_map *all);
void	free_seven(t_map *all);
void	free_eight(t_map *all);
void	free_nine(t_map *all);
void	free_ten(t_map *all);
void	load_images(t_map *all);
#endif