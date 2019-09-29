# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichemmou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 14:55:09 by ichemmou          #+#    #+#              #
#    Updated: 2019/06/10 16:58:26 by jcreux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
PATH_SRC = ./
PATH_INC = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = fdf.h

SRCS = main.c \
	   display.c \
	   ft_read.c \
	   get_values.c \
	   valid_line.c \
	   converters.c \
	   proj.c \
	   error.c \
	   new_img.c \
	   list_values.c \
	   ft_free.c \
	   init_proj.c \
	   browse.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRCS)))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
