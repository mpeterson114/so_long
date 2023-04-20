NAME = so_long.out



GNL = gnl/get_next_line.c gnl/get_next_line_utils.c
LIBRARY = -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX = minilibx/

SRC = main.c \
	map.c \

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $<

all:
		make -C $(MINILIBX)
		$(CC) $(CFLAGS) $(SRC) $(GNL) $(LIBRARY) -o $(NAME)





