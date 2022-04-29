# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozben <eozben@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 21:06:22 by eozben            #+#    #+#              #
#    Updated: 2022/03/12 19:32:22 by eozben           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	ft_substr.c ft_tolower.c ft_toupper.c ft_freestrarray.c \
	ft_free.c ft_striteri.c ft_append.c ft_printnl_fd.c ft_get_next_line.c \
	ft_get_next_line_utils.c

OBJ_PATH = ./objs/
OBJS = $(patsubst %.c,$(OBJ_PATH)%.o,$(SRC))

all:$(NAME)

$(NAME): $(OBJ_PATH) $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(OBJ_PATH)%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -rf $(OBJ_PATH)

fclean:
	@rm -rf $(NAME)
	@rm -rf $(OBJ_PATH)

re: fclean all