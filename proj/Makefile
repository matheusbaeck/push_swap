# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 23:11:40 by mamagalh@st       #+#    #+#              #
#    Updated: 2023/05/19 22:37:47 by mamagalh@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

SRCS =  main.c ft_parsing.c ft_moves.c ft_ps_utils.c \
	ft_algorythm_lower.c \
	ft_algorythm_radix.c \
	ft_algorythm.c ft_shadow.c ft_shadow_moves.c ft_entropy.c ft_modifier.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra -g3

all: $(NAME) clean

$(NAME): libft.a $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) libft.a -o $(NAME)

libft.a:
	cd libft && make

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) *.a

re: clean all
	