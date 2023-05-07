#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
//look up libraries

typedef struct t_game
{
    int fd;
    int mapheight;
    int mapwidth;
    int playercount;
    int collcheck;
    int exitcount;
    int x_axis;
    int y_axis;
    int counter;
    int collectablecount;

    char    **map;

    void    *floor;
    void    *wall;
    void    *player;
    void    *exit;
    void    *collectable;
    void    *blocker;
    void    *mlxpointer;
    void    *winpointer;
}   t_game;

typedef enum e_bool
{
    TRUE = 1,
    FALSE = 0,
}   t_bool;

/*typedef struct s_vector
{
    int x;
    int y;
}   t_vector;
*/

int  get_map_width(char *str);
int	add_line(t_game *game, char *line);
int	read_map(t_game *game, char **argv);
void    character_valid(t_game *game);
void    error_check(t_game *game);
void	place_player(t_game *game, int height, int width);
void	place_collectable(t_game *game, int height, int width);
void    put_images(t_game *game);
void    graphics(t_game *game, int height);
void	put_graphics(t_game *game);
int	exit_point(t_game *game);
int controls(int command, t_game *game);



#endif