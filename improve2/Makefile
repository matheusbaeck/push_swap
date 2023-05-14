# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 22:01:33 by mamagalh@st       #+#    #+#              #
#    Updated: 2023/05/01 22:07:05 by mamagalh@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

SRCS =  push_swap.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Werror -Wextra -g3

all: $(NAME) clean

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) dep/libft.a -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: clean all
