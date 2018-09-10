# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 14:56:05 by bmkhize           #+#    #+#              #
#    Updated: 2018/08/20 14:01:48 by bmkhize          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = -Wall -Werror -Wextra

HEADER = wolf3d.h

FUNCTIONS = main.c controls.c raycasting.c

all: $(NAME)

$(NAME):
	make -C libft/
	gcc libft/libft.a -o $(NAME) -I ~/.brew/include -L ~/.brew/lib \
		-lSDL2 $(FUNCTIONS)

ex:
	gcc libft/libft.a -o $(NAME) -I ~/.brew/include -L ~/.brew/lib \
		-lSDL2 $(FUNCTIONS)
	./$(NAME) test.wf3d

clean:
	cd libft && make fclean

fclean: clean
	cd libft && make clean

re: fclean all