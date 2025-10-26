# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhanlon <dhanlon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 09:35:28 by dhanlon           #+#    #+#              #
#    Updated: 2025/10/22 10:45:03 by dhanlon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_DIR = ./libs/libft

CFLAGS = -Wall -Werror -Wextra -I$(LIBFT_DIR)
LDFLAGS = -lmlx -lXext -lX11 -lm -L$(LIBFT_DIR) -lft

SRC = src/init_graphics.c \
	  src/so_long.c \
	  src/map_load.c \
	  src/map_parse.c \
	  src/map_validate.c \
	  src/map_solve.c \
	  src/map_elements.c \
	  src/draw_game.c \
	  src/free_map.c \
	  src/events.c
OBJ = $(SRC:.c=.o)

LIBFT_A = $(LIBFT_DIR)/libft.a

CC = gcc
RM = rm -f

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

all: $(LIBFT_A) $(NAME)

clean:
		$(RM) $(OBJ)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
