# Colors
COLOR_RESET = \033[0m
COLOR_YELLOW = \033[1;33m
COLOR_CYAN = \033[1;36m
COLOR_RED = \033[91m
COLOR_GREEN = \033[92m
COLOR_PINK = \033[95m

# Project Name
NAME = fdf

RM = rm -rf

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I $(PATH_HEADER)

# Paths
PATH_HEADER = include
PATH_LIBFT = include/libft
PATH_SRCS = srcs
PATH_OBJ = obj_dir

PATH_MLX = include/MLX42
MLX = ./include/MLX42/build/libmlx42.a
LIBS = -L$(PATH_MLX)/build -lmlx42 -L$(PATH_LIBFT) -lft -L"/opt/homebrew/opt/glfw/lib" -lglfw -framework Cocoa -framework OpenGL -framework IOKit

# Source Files Categories
ALGORITHM_SRC	=	01_render.c			\
					02_render.c

ERRORHANDLE_SRC	=	01_read_map.c		\
					02_read_map.c

TOOLS_SRC		=	keyboard.c			\
					menu.c				\
					mouse.c				\
					view.c

# Prepending the path
ALGORITHM_SRCS = $(addprefix $(PATH_SRCS)/algorithm/, $(ALGORITHM_SRC))
ERRORHANDLE_SRCS = $(addprefix $(PATH_SRCS)/errorhandle/, $(ERRORHANDLE_SRC))
TOOLS_SRCS = $(addprefix $(PATH_SRCS)/tools/, $(TOOLS_SRC))

# Combining All Sources
SRCS = $(PATH_SRCS)/fdf.c $(ALGORITHM_SRCS) $(ERRORHANDLE_SRCS) $(TOOLS_SRCS)

# Object Files
OBJS = $(addprefix $(PATH_OBJ)/, $(patsubst $(PATH_SRCS)/%.c, %.o, $(SRCS)))

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "[$(COLOR_YELLOW)$(NAME) --> OK$(COLOR_RESET)]\n${COLOR_GREEN}Success!${COLOR_RESET}"
	@echo "$(COLOR_PINK)\tUsage: ./$(NAME)$(COLOR_RESET)"

$(PATH_OBJ)/%.o: $(PATH_SRCS)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOR_GREEN)Compiled:$(COLOR_RESET) $<"

$(MLX):
	@cmake $(PATH_MLX) -B $(PATH_MLX)/build && make -C $(PATH_MLX)/build -j4

clean:
	@make clean -C $(PATH_LIBFT)
	@$(RM) $(PATH_MLX)/build
	@$(RM) $(PATH_OBJ)
	@echo "$(COLOR_RED)Cleaned up object files$(COLOR_RESET)"

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@$(RM) $(NAME)
	@echo "$(COLOR_RED)Cleaned up executables$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re
