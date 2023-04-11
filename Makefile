NAME = so_long.out

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

GNL = get_next_line.c get_next_line_utils.c
SRC_GNL = $(GNL)

SRC = 

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -lmlx -framework OpenGL -framework AppKit
REMOVE = rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $<





