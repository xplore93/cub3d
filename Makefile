# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estina <estina@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 12:56:12 by estina            #+#    #+#              #
#    Updated: 2019/12/05 18:35:46 by estina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D
HEADER			=	-I libft/
MAIN			=	main.c
SRCS			=	srcs/*.c
LIB_DIR			=	libft
LIB_SRC			=	$(shell find libft | fgrep ".c")
OBJ 			=	$(MAIN:.c=.o)
SOBJ 			=	$(SRCS:.c=.o)
LIBS			=	libft/libft.a
CC				=	@gcc -Wall -Wextra -Werror
FLAGS			=	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	-@make -C libft
	-$(CC) $(HEADER) $(MAIN) $(SRCS) $(LIBS) -o $(NAME) $(FLAGS)

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all