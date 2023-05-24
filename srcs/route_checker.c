/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:55:38 by mpeterso          #+#    #+#             */
/*   Updated: 2023/05/23 13:19:02 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void get_player_pos(char **copy, t_game *game)
{
    while (game->player_y < game->mapheight && copy[game->player_y][game->player_x] != 'P')
    {
        game->player_x = 1;
        while(game->player_x < game->mapwidth && copy[game->player_y][game->player_x] != 'P')
        {
            if (copy[game->player_y][game->player_x] == 'P')
                break ;
            game->player_x++;   
        }
        if (copy[game->player_y][game->player_x] == 'P')
            break ;
        game->player_y++;
    }
}

static void c_route(char **copy, t_game *game, int x, int y)
{
    if (copy[y][x] == 'C')
        game->c_check++;
    if (copy[y - 1][x] == '0' || copy[y + 1][x] == '0' || copy[y][x - 1] == '0' || copy[y][x + 1] == '0'
        || copy[y - 1][x] == 'C' || copy[y + 1][x] == 'C' || copy[y][x - 1] == 'C' || copy[y][x + 1] == 'C')
        copy[y][x] = 'Z';
    if (copy[y - 1][x] == '0' || copy[y - 1][x] == 'C')
        c_route(copy, game, x, y - 1);
    if (copy[y + 1][x] == '0' || copy[y + 1][x] == 'C')
        c_route(copy, game, x, y + 1);
    if (copy[y][x - 1] == '0' || copy[y][x - 1] == 'C')
        c_route(copy, game, x - 1, y);
    if (copy[y][x + 1] == '0' || copy[y][x + 1] == 'C')
        c_route(copy, game, x + 1, y);
    copy[y][x] = 'Z';
}

static void e_route(char **copy, t_game *game, int x, int y)
{
    if (copy[y][x] == 'E')
        game->e_check++;
    if (copy[y - 1][x] == '0' || copy[y + 1][x] == '0' || copy[y][x - 1] == '0' || copy[y][x + 1] == '0'
        || copy[y - 1][x] == 'C' || copy[y + 1][x] == 'C' || copy[y][x - 1] == 'C' || copy[y][x + 1] == 'C')
        copy[y][x] = 'Z';
    if (copy[y - 1][x] == '0' || copy[y - 1][x] == 'E' || copy[y - 1][x] == 'C')
        e_route(copy, game, x, y - 1);
    if (copy[y + 1][x] == '0' || copy[y + 1][x] == 'E' || copy[y + 1][x] == 'C')
        e_route(copy, game, x, y + 1);
    if (copy[y][x - 1] == '0' || copy[y][x - 1] == 'E' || copy[y][x - 1] == 'C')
        e_route(copy, game, x - 1, y);
    if (copy[y][x + 1] == '0' || copy[y][x + 1] == 'E' || copy[y][x + 1] == 'C')
        e_route(copy, game, x + 1, y);
    copy[y][x] = 'Z';
}

void    check_route(char **copy, t_game *game)
{
    int row;

    row = 0;
    get_player_pos(copy, game);
    c_route(copy, game, game->player_x, game->player_y);
    if (game->c_check != game->c_count)
    {
        printf("\n\033[1;31mError: some collectables are inaccessible\033[0m\n");
        exit_point(game);
    }
    while (row < game->mapheight)
        free(copy[row++]);
    copy_map(copy, game);
    e_route(copy, game, game->player_x, game->player_y);
    row = 0;
    while (row < game->mapheight)
        free(copy[row++]);
    free(copy);
    if (game->e_check != 1)
    {
        printf("\n\033[1;31mError: exit is inaccessible\033[0m\n");
        exit_point(game);
    }
} 






