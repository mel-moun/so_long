# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 13:01:04 by mel-moun          #+#    #+#              #
#    Updated: 2023/07/28 19:24:29 by mel-moun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME2 = so_long_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
ARGS = -Iinclude -lglfw -L"/Users/mel-moun/.brew/opt/glfw/lib/"
MLX42 = /Users/mel-moun/MLX42/build/libmlx42.a

CFILES =ft_split.c\
		get_next_line.c\
		get_next_line_bonus.c\
		graphic1.c\
		graphic.c\
		mandatory.c\
		map.c\
		map1.c\
		solong.c\
		utils.c\
		utils1.c\
		free_images.c\
		free_images_t.c\
		map3.c\
		load_images.c\

CFILES2 = ft_split.c\
		get_next_line.c\
		get_next_line_bonus.c\
		graphic1.c\
		graphic.c\
		so_long_bonus.c\
		map.c\
		map1.c\
		solong.c\
		utils.c\
		utils1.c\
		bonus_utils.c\
		free_images.c\
		free_images_t.c\
		map3.c\
		load_images.c\

OBJECTS=$(CFILES:.c=.o)
OBJECTS2=$(CFILES2:.c=.o)

all : $(NAME)
bonus : $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX42) $(ARGS) -o $(NAME)

$(NAME2): $(OBJECTS2)
	$(CC) $(CFLAGS) $(OBJECTS2) $(MLX42) $(ARGS) -o $(NAME2)
	
clean:
	rm -f $(OBJECTS) $(OBJECTS2)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re bonus