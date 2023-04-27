#include "so_long.h"

static int  horizontal_walls(t_game *game)
{
    int x;
    int y;

    x = game->mapwidth;
    y = 0;
    while (y < x)
    {
        if (!(game->map[0][i] == '1' && game->map[game->mapheight - 1][y] == '1'))
            return (0);
        y++;
    }
    return (1);
}

static int  vertical_walls(t_game *game)
{
    int x;
    int y;

    x = game->mapwidth;
    y = 0;
    while (y < x)
    {
        if (!(game->map[y][0] == '1' && game->map[y][x - 1] == '1'))
            return (0);
        y++;
    }
    return (1);
}

