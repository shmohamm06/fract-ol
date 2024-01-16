#
#
RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
LIB_DIR = libft
MLX_DIR = mlx_fractol

SRCS = main.c julia.c mandelbrot.c tricorn.c bonus.c bonus_2.c args_check.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(LIB_DIR)/libft.a $(MLX_DIR)/libmlx.a $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)/libft.a -o $(NAME) $(FRAMEWORKS) -L$(MLX_DIR) -lmlx
	@echo ""
	@echo "$(GREEN)  █████▒██▀███   ▄▄▄       ▄████▄  ▄▄▄█████▓ ▒█████   ██▓    "
	@echo "▓██   ▒▓██ ▒ ██▒▒████▄    ▒██▀ ▀█  ▓  ██▒ ▓▒▒██▒  ██▒▓██▒    "
	@echo "▒████ ░▓██ ░▄█ ▒▒██  ▀█▄  ▒▓█    ▄ ▒ ▓██░ ▒░▒██░  ██▒▒██░    "
	@echo "░▓█▒  ░▒██▀▀█▄  ░██▄▄▄▄██ ▒▓▓▄ ▄██▒░ ▓██▓ ░ ▒██   ██░▒██░    "
	@echo "░▒█░   ░██▓ ▒██▒ ▓█   ▓██▒▒ ▓███▀ ░  ▒██▒ ░ ░ ████▓▒░░██████▒"
	@echo " ▒ ░   ░ ▒▓ ░▒▓░ ▒▒   ▓▒█░░ ░▒ ▒  ░  ▒ ░░   ░ ▒░▒░▒░ ░ ▒░▓  ░"
	@echo " ░       ░▒ ░ ▒░  ▒   ▒▒ ░  ░  ▒       ░      ░ ▒ ▒░ ░ ░ ▒  ░"
	@echo " ░ ░     ░░   ░   ░   ▒   ░          ░      ░ ░ ░ ▒    ░ ░   "
	@echo "          ░           ░  ░░ ░                   ░ ░      ░  ░  "
	@echo "                                   "
	@echo "Created: $(words $(OBJS)) object file(s) for Fractol"
	@echo "Created: $(NAME)"


$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

$(LIB_DIR)/libft.a:
	@$(MAKE) -C $(LIB_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(MLX_DIR)/libmlx.a
	@rm -f $(LIB_DIR)/libft.a
	@echo ""
	@echo "$(YELLOW)  █████▒██▀███   ▄▄▄       ▄████▄  ▄▄▄█████▓ ▒█████   ██▓    "
	@echo "▓██   ▒▓██ ▒ ██▒▒████▄    ▒██▀ ▀█  ▓  ██▒ ▓▒▒██▒  ██▒▓██▒    "
	@echo "▒████ ░▓██ ░▄█ ▒▒██  ▀█▄  ▒▓█    ▄ ▒ ▓██░ ▒░▒██░  ██▒▒██░    "
	@echo "░▓█▒  ░▒██▀▀█▄  ░██▄▄▄▄██ ▒▓▓▄ ▄██▒░ ▓██▓ ░ ▒██   ██░▒██░    "
	@echo "░▒█░   ░██▓ ▒██▒ ▓█   ▓██▒▒ ▓███▀ ░  ▒██▒ ░ ░ ████▓▒░░██████▒"
	@echo " ▒ ░   ░ ▒▓ ░▒▓░ ▒▒   ▓▒█░░ ░▒ ▒  ░  ▒ ░░   ░ ▒░▒░▒░ ░ ▒░▓  ░"
	@echo " ░       ░▒ ░ ▒░  ▒   ▒▒ ░  ░  ▒       ░      ░ ▒ ▒░ ░ ░ ▒  ░"
	@echo " ░ ░     ░░   ░   ░   ▒   ░          ░      ░ ░ ░ ▒    ░ ░   "
	@echo "          ░           ░  ░░ ░                   ░ ░      ░  ░  "
	@echo "                                   "
	@echo "Created: $(words $(OBJS)) object file(s) for Fractol"
	@echo "Created: $(NAME)"
	@echo "Removed: $(words $(OBJS)) object file(s) for Fractol"
	@echo "Removed: $(NAME)"

re: fclean all

.PHONY: all clean fclean re