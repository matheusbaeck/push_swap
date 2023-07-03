# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: math42 <math42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 23:11:40 by mamagalh@st       #+#    #+#              #
#    Updated: 2023/05/18 01:38:11 by math42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

SRCS =  main.c ft_parsing.c ft_moves.c ft_ps_utils.c \
	ft_algorythm_lower.c \
	ft_algorythm_radix.c \
	ft_algorythm_entropy.c ft_algorythm_entropy_modifier.c ft_algorythm_entropy_classify.c ft_algorythm_entropy_moves.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra -g3

all: $(NAME) clean

$(NAME): libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)

libft.a:
	cp -f libft/libft.a ./libft.a
	cp -f libft/libft.h ./libft.h

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) *.a

re: clean all
	