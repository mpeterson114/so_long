#include "so_long.h"

static int  correct_move(t_game *game, int x, int y)
{
    if (game->map[y][x] == 'E')
    {
        if (game->collectablecount != 0)
            return (0);
        printf("\n\033[1;32mYou Won!\033[0m\n");
        exit_point(game);
    }
    if (game->map[y][x] == '0')
    {
        game->map[y][x] = 'P';
        game->x_axis = x;
        game->y_axis = y;
        game->counter++;
    }
    if (game->map[y][x] == 'C')
    {
        game->map[y][x] = 'P';
        game->x_axis = x;
        game->y_axis = y;
        game->collectablecount--;
        game->counter++;
    }
    if (game->map[y][x] == 'H')
    {
        printf("\n\033[1;31mGAME OVER, Drive better next time...\033[0m\n");
        exit_point(game);
    }
    return (1);
}

static int  key_up_down(t_game *game, int keycode)
{
    int checker;
    int x;
    int y;

    x = game->x_axis;
    y = game->y_axis;
    if (keycode == 13)
    {
        y--;
        if (game->map[y][x] == '1')
            return (0);
        checker = correct_move(game, x, y);
        if (!checker)
            return (0);
        game->map[y + 1][x] = '0'; 
    }
    else if (keycode == 1)
    {
        y++;
        if (game->map[y][x] == '1')
            return (0);
        checker = correct_move(game, x, y);
        if (!checker)
            return (0);
        game->map[y - 1][x] = '0'; 
    }
    printf("Moves taken: %i\n", game->counter);
    printf("Collectables count: %i\n", game->collectablecount);
    printf("%d\n", game->x_axis);
    printf("%d\n", game->y_axis);
    printf("%c\n", game->map[y][x]);
    return (1);
}

static int  key_left_right(t_game *game, int keycode)
{
    int checker;
    int x;
    int y;

    x = game->x_axis;
    y = game->y_axis;
    if (keycode == 0)
    {
        x--;
        if (game->map[y][x] == '1')
            return (0);
        checker = correct_move(game, x, y);
        if (!checker)
            return (0);
        game->map[y][x + 1] = '0'; 
    }
    else if (keycode == 2)
    {
        x++;
        if (game->map[y][x] == '1')
            return (0);
        checker = correct_move(game, x, y);
        if (!checker)
            return (0);
        game->map[y][x - 1] = '0'; 
    }
    printf("Moves taken: %i\n", game->counter);
    printf("%d\n", game->x_axis);
    printf("%d\n", game->y_axis);
    printf("%c\n", game->map[y][x]);
    return (1);
}

int controls(int command, t_game *game)
{
    int check;
    //int x;
    //int y;

    //x = game->x_axis;
    //y = game->y_axis;
    if (command == 53)
        exit_point(game);
    if (command == 13)
        check = key_up_down(game, command);
    if (command == 1)
        check = key_up_down(game, command);
    if (command == 0)
        check = key_left_right(game, command);
    if (command == 2)
        check = key_left_right(game, command);
    if (check)
        put_graphics(game);
    return (1);
}



