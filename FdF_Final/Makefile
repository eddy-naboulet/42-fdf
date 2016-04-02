# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enaboule <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/02 15:32:13 by enaboule          #+#    #+#              #
#    Updated: 2016/04/02 15:35:21 by enaboule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ft_color_value.c ft_create_struct.c ft_draw.c ft_error_fdf.c ft_event.c\
ft_hud.c ft_modify_value.c ft_parsing.c main.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

FW = -lmlx -framework OpenGL -framework AppKit

LIB =  -L/usr/local/lib/ libft/libft.a


all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) $(LIB) -I/usr/local/include $(FW) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
	make -C libft/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
