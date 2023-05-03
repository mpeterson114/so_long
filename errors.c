#include "so_long.h"

static int  horizontal_walls(t_game *game)
{
    int width;

    width = 0;
    while (width < game->mapwidth)
    {
        if (!(game->map[0][width] == '1' && game->map[game->mapheight - 1][width] == '1'))
            return (0);
        width++;
    }
    return (1);
}

static int  vertical_walls(t_game *game)
{
    int x;
    int y;

    x = game->mapwidth;
    y = 0;
    while (y < game->mapheight)
    {
        if (!(game->map[y][0] == '1' && game->map[y][x - 1] == '1'))
            return (0);
        y++;
    }
    return (1);
}

static void count_checker(t_game *game, int height, int width)
{
    if (game->map[height][width] != '1' &&
    game->map[height][width] != '0' &&
    game->map[height][width] != 'P' &&
    game->map[height][width] != 'C' &&
    game->map[height][width] != 'E' &&
    game->map[height][width] != '\n')
    {
        printf("\nError here: %c\n", game->map[height][width]);
        exit_point(game);
    }
    if (game->map[height][width] == 'C')
        game->columncount++;
    else if (game->map[height][width] == 'P')
        game->playercount++;
    else if (game->map[height][width] == 'E')
        game->exitcount++;
}

void    character_valid(t_game *game)
{
    int height;
    int width;

    height = 0;
    while (height < game->mapheight - 1)
    {
        width = 0;
        while (width <= game->mapwidth)
        {
            count_checker(game, height, width);
            width++;
        }
        height++;
    }
    if (!(game->playercount = 1 && game->columncount > 1 && game->exitcount == 1))
    {
        printf("\nError\nEither player, exit or collectable issue\n");
        exit_point(game);
    }
}

void    error_check(t_game *game)
{
    int verticalwalls;
    int horizontalwalls;

    verticalwalls = vertical_walls(game);
    horizontalwalls = horizontal_walls(game);
    printf("%d\n", verticalwalls);
    printf("%d\n", horizontalwalls);
    if (!verticalwalls || !horizontalwalls)
    {
        printf("\nError\nMap missing walls\n");
        exit_point(game);
    }
    character_valid(game);
}

