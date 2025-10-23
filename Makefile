MLX_DIR = ./minilibx-linux
LIBFT_DIR = ./libs/libft

CFLAGS = -g -I$(MLX_DIR) -I$(LIBFT_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -L$(LIBFT_DIR) -lft

SRC = src/init_graphics.c \
	  src/so_long.c \
	  src/map_load.c \
	  src/map_parse.c \
	  src/map_validate.c \
	  src/map_solve.c \
	  src/map_elements.c \
	  src/draw_game.c \
	  src/free_memory.c \
	  src/events.c
OBJ = $(SRC:.c=.o)
TARGET = so_long

LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(LIBFT_A) $(TARGET)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re