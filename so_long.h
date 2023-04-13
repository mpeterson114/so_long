#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdio.h>

# define IMG_SIZE 64

typedef enum e_bool
{
    TRUE = 1,
    FALSE = 0,
}   t_bool;

typedef struct s_vector
{
    int x;
    int y;
}   t_vector;

//Tile types
typedef enum e_tiletype
{
    EMPTY = '0',
    WALL = '1',
    COLLECTABLE = 'C',
    PLAYER = 'P',
    EXIT = 'E',
    ENEMY = 'M',
    FOLLOWER = 'F',
}   t_tiletype;

typedef enum e_enemytype
{
    HORIZONTAL = 'H',
    VERTICAL = 'V',
    FOLLOWER = 'F',
}   t_enemytype;

//Struct for tiles
typedef struct s_tile
{
    t_tiletype  type;
    t_tiletype  orig_type;
    t_vector    position;
    struct s_tile   *up;
    struct s_tile   *down;
    struct s_tile   *left;
    struct s_tile   *right;
}   t_tile;

#endif