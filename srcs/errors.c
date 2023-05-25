/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:55:51 by mpeterso          #+#    #+#             */
/*   Updated: 2023/05/25 13:05:04 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	horizontal_walls(t_game *game)
{
	int	width;

	width = 0;
	while (width < game->mapwidth)
	{
		if (!(game->map[0][width] == '1'
			&& game->map[game->mapheight - 1][width] == '1'))
			return (0);
		width++;
	}
	return (1);
}

static int	vertical_walls(t_game *game)
{
	int	x;
	int	y;	

	x = game->mapwidth;
	y = 0;
	while (y < game->mapheight)
	{
		if (((int) ft_strlen(game->map[y]) - 1) != x)
		{
			printf("\n\033[1;31mError: Map must be a rectangle\033[0m\n");
			exit_point(game);
		}
		if (!(game->map[y][0] == '1' && game->map[y][x - 1] == '1'))
			return (0);
		y++;
	}
	return (1);
}

static void	count_checker(t_game *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
	game->map[height][width] != '0' &&
	game->map[height][width] != 'P' &&
	game->map[height][width] != 'C' &&
	game->map[height][width] != 'E' &&
	game->map[height][width] != '\n')
	{
		printf("\n\033[1;31mError, invalid character here: %c\033[0m\n",
			game->map[height][width]);
		exit_point(game);
	}
	if (game->map[height][width] == 'C')
		game->c_count++;
	else if (game->map[height][width] == 'P')
		game->playercount++;
	else if (game->map[height][width] == 'E')
		game->exitcount++;
}

void	character_valid(t_game *game)
{
	int	height;
	int	width;	

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
	if (!(game->playercount == 1 && game->c_count >= 1 && game->exitcount == 1))
	{
		printf("\n\033[1;31mError:Wrong # players, exits or collectables\033[0m\n");
		exit_point(game);
	}
}

void	error_check(t_game *game)
{
	int		verticalwalls;
	int		horizontalwalls;
	char	**copy;

	verticalwalls = vertical_walls(game);
	horizontalwalls = horizontal_walls(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("\n\033[1;31mError: Map is missing walls\033[0m\n");
		exit_point(game);
	}
	character_valid(game);
	copy = (char **)malloc(sizeof(char *) * (game->mapheight));
	copy_map(copy, game);
	check_route(copy, game);
}
