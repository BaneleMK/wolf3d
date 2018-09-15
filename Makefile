# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmkhize <bmkhize@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 14:56:05 by bmkhize           #+#    #+#              #
#    Updated: 2018/09/15 12:34:12 by bmkhize          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = -Wall -Werror -Wextra

HEADER = includes/wolf3d.h

SRC = src/

FUNCTIONS = $(SRC)main.c \
			$(SRC)controls.c \
			$(SRC)raycasting.c \
			$(SRC)moregraphics.c \
			$(SRC)validate.c

all: $(NAME)

$(NAME): $(FUNCTIONS)
	cd libft && make all
	gcc $(FLAGS) libft/libft.a -o $(NAME) -I ~/.brew/include -L ~/.brew/lib \
		-lSDL2 $(FUNCTIONS)

ex:
	gcc $(FLAGS) libft/libft.a -o $(NAME) -I ~/.brew/include -L ~/.brew/lib \
		-lSDL2 $(FUNCTIONS)

ubuntu:
	gcc $(FLAGS) $(FUNCTIONS) -o $(NAME) `pkg-config --cflags --libs sdl2` -lm \
	 libft/libft.a

clean:
	@ cd libft && make fclean

fclean: clean
	@ cd libft && make clean
	@ rm -f $(NAME)

re: fclean all
