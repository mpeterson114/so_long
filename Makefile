ORANGE =		\033[38;5;209m
CYAN =			\033[0;96m
YELLOW =		\033[0;93m
RED =			\033[0;91m
GREEN =			\033[0;92m
GRAY =			\033[0;90m

NAME = so_long
NAME_BONUS = so_long_bonus

LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX = minilibx/

SRCS = ./srcs/errors.c \
	./srcs/images.c \
	./srcs/main.c \
	./srcs/map.c \
	./srcs/moves.c \
	./srcs/route_checker.c \
	./srcs/utils.c \
	./gnl/get_next_line.c \
	./gnl/get_next_line_utils.c \

SRCS_BONUS = ./bonus_srcs/errors_bonus.c \
	./bonus_srcs/images_bonus.c \
	./bonus_srcs/main_bonus.c \
	./bonus_srcs/map_bonus.c \
	./bonus_srcs/moves_bonus.c \
	./bonus_srcs/route_checker_bonus.c \
	./bonus_srcs/utils_bonus.c \
	./gnl/get_next_line.c \
	./gnl/get_next_line_utils.c \
	
CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

%.o: %.c
	@echo "$(YELLOW) Compiling	$(GRAY)$<"
	@$(CC) $(CFLAGS) -c $< -o $@

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(MINILIBX) --silent
		@$(CC) $(CFLAGS) $(SRCS) $(LIBRARY) -o $(NAME)
		@echo "\n$(GREEN) Objects and executables created successfully"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
			@make -C $(MINILIBX) --silent
			@$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBRARY) -o $(NAME_BONUS)
			@echo "\n$(GREEN) Bonus objects and executables created successfully"

clean:
		@$(REMOVE) $(OBJS) $(OBJS_BONUS)
		@echo "\n$(CYAN) Objects cleaned successfully"

fclean: 
		make clean -C $(MINILIBX)
		$(REMOVE) $(NAME) $(NAME_BONUS)
		$(REMOVE) $(OBJS) $(OBJS_BONUS)
		@echo "\n$(ORANGE)Objects and executables deleted successfully"

re:	fclean all

rebonus: fclean $(NAME_BONUS)

.PHONY: all clean fclean re rebonus





