# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estina <estina@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 12:56:12 by estina            #+#    #+#              #
#    Updated: 2020/01/07 13:52:03 by estina           ###   ########.fr        #
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
LIBS			=	libft/libft.a mlx/libmlx.a
CC				=	@gcc -Wall -Wextra -Werror
FLAGS			=	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	-@make -C libft
	-@make -C mlx --silent
	-$(CC) $(HEADER) $(MAIN) $(SRCS) $(LIBS) -o $(NAME) $(FLAGS)

bonus:
	-@make -C libft
	-@make -C mlx --silent
	-$(CC) $(HEADER) $(MAIN) $(SRCS) $(LIBS) -o $(NAME) $(FLAGS)

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make clean -C mlx

mlx_clean:
	-@make clean -C mlx --silent

re: mlx_clean fclean all