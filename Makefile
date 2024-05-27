# Colors
COLOR_RESET = \033[0m
COLOR_YELLOW = \033[1;33m
COLOR_CYAN = \033[1;36m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_PINK = \033[95m

NAME = fdf

PATH_LIBFT = libft
PATH_SRCS = srcs

PATH_HEADER = includes
OBJ_DIR = objs

RM = rm -rf
CC = cc
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX := ./includes/MLX42

#! 42 - BKK Machine
# LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
#! Personal Machine
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -L"/opt/homebrew/opt/glfw/lib" -pthread -lm

ALGORITHM_SRC =		convert_matrix.c	\
					get_dims.c			\
					map_read.c			\
					render.c			\
					draw_line.c

MISC_SRC =			ft_free.c			\
					parser.c			\
					utils.c				\
					# color.c

ALGORITHM_SRCS = $(addprefix $(PATH_SRCS)/algorithm/, $(ALGORITHM_SRC))
MISC_SRCS = $(addprefix $(PATH_SRCS)/misc/, $(MISC_SRC))

SRCS = $(PATH_SRCS)/fdf.c $(ALGORITHM_SRCS) $(MISC_SRCS)
OBJ_FILES := $(SRCS:$(PATH_SRCS)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(PATH_SRCS)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(PATH_HEADER) -c $< -o $@
	@printf "$(COLOR_GREEN)Compiled: $(CC) $(CFLAGS)$(COLOR_RESET) %-40s\r" "$(notdir $<)"
	@printf "\n"

all: libmlx $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_FILES)
	@make -C $(PATH_LIBFT)
	@make libmlx
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBS) -L$(PATH_LIBFT) -lft
	@printf "[$(COLOR_YELLOW)$(NAME) --> OK$(COLOR_RESET)]\n ${COLOR_GREEN}Success!${COLOR_RESET}\n"
	@printf "$(COLOR_PINK)\tUsage: ./fdf [PATH Map]$(COLOR_RESET)\n"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

libmlx:
	git clone https://github.com/codam-coding-college/MLX42.git $(PATH_HEADER)/MLX42; \
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \

norm:
	@printf "$(COLOR_YELLOW)"
	@norminette $(PATH_SRCS) | grep -E "Error"
	@printf "$(COLOR_RESET)"

clean:
	@$(RM) $(OBJ_DIR)
	@make -C $(PATH_LIBFT) clean
	@rm -rf $(LIBMLX)
	@echo "$(COLOR_RED)Cleaned up MLX42$(COLOR_RESET)"
	@rm -rf .DS_Store

fclean: clean
	@$(RM) $(NAME)
	@make -C $(PATH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libmlx
