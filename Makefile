NAME = FdF

LIBRARY_DIR = ./libft
MLX = ./mlx_linux/libmlx.a
LIBFT = $(LIBRARY_DIR)/libft.a
PRINTF = $(LIBRARY_DIR)/ft_printf/libftprintf.a

CC = cc
# 
CFLAGS = -Wall -Wextra -Werror -Iincludes -g -fsanitize=address

RM = rm -f

SRCS = main.c \
	   srcs/math_utils.c \
	   srcs/controls.c \
	   srcs/mouse.c \
	   srcs/keyboard.c \
	   srcs/draw.c \
	   srcs/draw_line.c \
	   srcs/project.c \
	   srcs/read_file.c \
	   srcs/utils.c \
	   srcs/utils_2.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(PRINTF) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 

$(LIBFT):
	@$(MAKE) -C $(LIBRARY_DIR) all

$(MLX): 
	@$(MAKE) -C ./mlx_linux

clean:
	@$(MAKE) -C $(LIBRARY_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBRARY_DIR) fclean
	@$(MAKE) -C ./mlx_linux clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re