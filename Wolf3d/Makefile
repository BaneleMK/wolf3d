# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmkhize <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/19 14:56:05 by bmkhize           #+#    #+#              #
#    Updated: 2018/08/27 14:05:25 by bmkhize          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = -Wall -Werror -Wextra

HEADER = wolf3d.h

FUNCTIONS = main.c

all: $(NAME)

$(NAME):
	@ cd libft && make all
	@ gcc $(FLAGS) $(FUNCTIONS) -L./libft -lft -o $(NAME) -lmlx -framework \
		OpenGL -framework AppKit

ex:
	@ gcc $(FLAGS) $(FUNCTIONS) -L./libft -lft -o $(NAME) -lmlx -framework \
	OpenGL -framework AppKit

clean:
	@ cd libft && make fclean
	@ rm -f $(OBJECTS)

fclean: clean
	@ cd libft && make clean
	@ rm -f $(NAME)

re: fclean all
