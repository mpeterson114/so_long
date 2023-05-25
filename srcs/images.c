/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:55:40 by mpeterso          #+#    #+#             */
/*   Updated: 2023/05/25 12:03:58 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 50, height * 50);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer, game->winpointer,
		game->collectable, width * 50, height * 50);
	game->c_remaining++;
}

void	put_images(t_game *game)
{
	game->player = xpm_check(game, "graphics/foodtruck.xpm");
	game->collectable = xpm_check(game, "graphics/pretzel.xpm");
	game->wall = xpm_check(game, "graphics/grass2.xpm");
	game->exit = xpm_check(game, "graphics/fair.xpm");
	game->floor = xpm_check(game, "graphics/floorblank.xpm");
}

void	graphics(t_game *game, int height)
{
	int	width;

	while (height < game->mapheight)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			else if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			else if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer,
					game->wall, width * 50, height * 50);
			else if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer,
					game->exit, width * 50, height * 50);
			else if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer,
					game->floor, width * 50, height * 50);
			width++;
		}
		height++;
	}
}

void	put_graphics(t_game *game)
{
	int	height;

	game->c_remaining = 0;
	height = 0;
	graphics(game, height);
}
