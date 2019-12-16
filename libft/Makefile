# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estina <estina@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 13:13:02 by estina            #+#    #+#              #
#    Updated: 2019/12/05 13:35:18 by estina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_memset.c		ft_toupper.c	ft_strtrim.c	\
			ft_bzero.c		ft_tolower.c	ft_split.c		\
			ft_memcpy.c		ft_strchr.c		ft_itoa.c		\
			ft_memccpy.c	ft_strrchr.c	ft_strmapi.c	\
			ft_memmove.c	ft_strncmp.c	ft_putchar_fd.c	\
			ft_memchr.c		ft_strlcpy.c	ft_putstr_fd.c	\
			ft_memcmp.c		ft_strlcat.c	ft_putendl_fd.c	\
			ft_strlen.c		ft_strnstr.c	ft_putnbr_fd.c	\
			ft_isalpha.c	ft_atoi.c		get_next_line.c	\
			ft_isdigit.c	ft_calloc.c						\
			ft_isalnum.c	ft_strdup.c						\
			ft_isascii.c	ft_substr.c						\
			ft_isprint.c	ft_strjoin.c

BONS	=	ft_lstnew_bonus.c		ft_lstadd_front_bonus.c	\
			ft_lstsize_bonus.c		ft_lstlast_bonus.c		\
			ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	\
			ft_lstclear_bonus.c		ft_lstiter_bonus.c		\
			ft_lstmap_bonus.c

PRSR	=	printf/srcs
PRTF	=	printf

PRNT	=	flag_minus_handle.c		flag_none_handle.c				\
			flag_point_handle.c		flag_zero_handle.c				\
			handle_char.c			handle_float.c					\
			handle_n.c				handle.c						\
			handle_pointer.c		handle_string.c					\
			handle_types.c			hex_itoa.c						\
			long_long_itoa.c		unsigned_itoa.c					\
			long_itoa.c				unsigned_long_itoa.c			\

PRMN	=	ft_printf.c

PRTSRC	=	$(addprefix $(PRSR)/,$(PRNT))
PRTFC	=	$(addprefix $(PRTF)/,$(PRMN))

GCC		=	@gcc -Wall -Wextra -Werror

OBJECTS	=	$(SRCS:.c=.o)
BOBJ	=	$(BONS:.c=.o)
POBJ	=	$(PRNT:.c=.o)
PROBJ	=	$(PRMN:.c=.o)

HEADERS = -I ./ -I printf/

all: $(NAME)

$(NAME): $(PRTSRC) $(PRTFC) $(BONS) $(SRCS) libft.h
	-$(GCC) -I./ -c $(BONS) $(SRCS) $(PRTSRC) $(PRTFC)
	-@ar rc $(NAME) $(BOBJ) $(OBJECTS) $(POBJ) $(PROBJ)
	-@ranlib $(NAME)

clean:
	-@rm -f $(OBJECTS) $(BOBJ) $(POBJ) $(PROBJ)

fclean: clean
	-@rm -f $(NAME)

re: fclean all
