# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 10:37:38 by mamagalh@st       #+#    #+#              #
#    Updated: 2023/03/28 22:11:15 by mamagalh@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

HEADER_NAME = libft.h

NAME_BONUS = libft_bonus.a

CC = cc

FLAGS = -Wall -Wextra -Werror -c -g -o

LIB_CC = ar rcs

LIB_PATH = /Users/mamagalh/42Projects/\#lib/

HEADER_PATH = /Users/mamagalh/42Projects/\#header/

SRC = ft_islower.c \
	ft_isupper.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_memmove.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_strtrim.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ) $(HEADER_NAME)
	$(LIB_CC) $(NAME) $(OBJ) $(HEADER_NAME)
	ln -f $(NAME) $(LIB_PATH)$(NAME)
	ln -f $(HEADER_NAME) $(HEADER_PATH)$(HEADER_NAME)

%.o:%.c
	$(CC) $(FLAGS) $@ $<

clean:
	rm -rf *.o *.dSYM *.out *.a

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(LIB_PATH)$(NAME) $(HEADER_PATH)$(HEADER_NAME)

re: fclean all

bonus_re: fclean bonus

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ) $(BONUS_OBJ) $(HEADER_NAME)
	$(LIB_CC) $(NAME_BONUS) $(OBJ) $(BONUS_OBJ)
	ln -f $(NAME:.a=_bonus.a) $(NAME)
	ln -f $(NAME:.a=_bonus.a) $(LIB_PATH)$(NAME)
	ln -f $(HEADER_NAME) $(HEADER_PATH)$(HEADER_NAME)