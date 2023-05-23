ORANGE =		\033[38;5;209m
CYAN =			\033[0;96m
YELLOW =		\033[0;93m
RED =			\033[0;91m
GREEN =			\033[0;92m
GRAY =			\033[0;90m

NAME = so_long

LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX = minilibx/

SRCS = main.c \
	map.c \
	images.c \
	errors.c \
	moves.c \
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	utils.c \
	route_checker.c \
	
CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

%.o: %.c
	@echo "$(YELLOW) Compiling	$(GRAY)$<"
	@$(CC) $(CFLAGS) -c $< -o $@

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		make -C $(MINILIBX)
		@$(CC) $(CFLAGS) $(SRCS) $(LIBRARY) -o $(NAME)
		@echo "\n$(GREEN) Objects and executables created successfully"

clean:
		@$(REMOVE) $(OBJS)
		@echo "\n$(CYAN) Objects cleaned successfully"

fclean: 
		make clean -C $(MINILIBX)
		$(REMOVE) $(NAME)
		$(REMOVE) $(OBJS)
		@echo "\n$(ORANGE)Objects and executables deleted successfully"

re:	fclean all

.PHONY: all clean fclean re





