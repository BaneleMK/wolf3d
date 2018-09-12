# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmkhize <bmkhize@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 14:56:05 by bmkhize           #+#    #+#              #
#    Updated: 2018/09/12 14:33:57 by bmkhize          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = -Wall -Werror -Wextra

HEADER = wolf3d.h

FUNCTIONS = main.c controls.c raycasting.c moregraphics.c validate.c

all: $(NAME)

$(NAME):
	cd libft && make all
	gcc $(FLAGS) libft/libft.a -o $(NAME) -I ~/.brew/include -L ~/.brew/lib \
		-lSDL2 $(FUNCTIONS)

ex:
	gcc $(FLAGS) libft/libft.a -o $(NAME) -I ~/.brew/include -L ~/.brew/lib \
		-lSDL2 $(FUNCTIONS)

clean:
	@ cd libft && make fclean
	@ rm -f $(OBJECTS)

fclean: clean
	@ cd libft && make clean
	@ rm -f $(NAME)

re: fclean all
