/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:55:36 by mpeterso          #+#    #+#             */
/*   Updated: 2023/05/25 12:12:49 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	correct_move(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->c_remaining != 0)
			return (0);
		printf("\n\033[1;32mCongratulations, you made it to the fair!\033[0m\n");
		exit_point(game);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->moves_count++;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->c_remaining--;
		game->moves_count++;
	}
	return (1);
}

static int	key_up_down(t_game *game, int keycode, int y, int x)
{
	int	checker;

	if (keycode == 13 || keycode == 126)
	{
		y--;
		if (game->map[y][x] == '1')
			return (0);
		checker = correct_move(game, x, y);
		if (!checker)
			return (0);
		game->map[y + 1][x] = '0';
	}
	else if (keycode == 1 || keycode == 125)
	{
		y++;
		if (game->map[y][x] == '1')
			return (0);
		checker = correct_move(game, x, y);
		if (!checker)
			return (0);
		game->map[y - 1][x] = '0';
	}
	printf("Moves taken: %i\n", game->moves_count);
	printf("Collectables left: %i\n", game->c_remaining);
	return (1);
}

static int	key_left_right(t_game *game, int keycode, int y, int x)
{
	int	checker;

	if (keycode == 0 || keycode == 123)
	{
		x--;
		if (game->map[y][x] == '1')
			return (0);
		checker = correct_move(game, x, y);
		if (!checker)
			return (0);
		game->map[y][x + 1] = '0';
	}
	else if (keycode == 2 || keycode == 124)
	{
		x++;
		if (game->map[y][x] == '1')
			return (0);
		checker = correct_move(game, x, y);
		if (!checker)
			return (0);
		game->map[y][x - 1] = '0';
	}
	printf("Moves taken: %i\n", game->moves_count);
	printf("Collectables left: %i\n", game->c_remaining);
	return (1);
}

int	controls(int command, t_game *game)
{
	int	x;
	int	y;
	int	check;	

	x = game->x_axis;
	y = game->y_axis;
	if (command == 53)
		exit_point(game);
	if (command == 13 || command == 126)
		check = key_up_down(game, command, y, x);
	if (command == 1 || command == 125)
		check = key_up_down(game, command, y, x);
	if (command == 0 || command == 123)
		check = key_left_right(game, command, y, x);
	if (command == 2 || command == 124)
		check = key_left_right(game, command, y, x);
	if (check)
		put_graphics(game);
	return (1);
}
