#include "so_long.h"

void	place_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->collectable, width * 40, height * 40);
	game->collectablecount++;
}

void    put_images(t_game *game)
{
    int	x;
	int	y;

	game->player = mlx_xpm_file_to_image(game->mlxpointer, "redpepper.xpm", &x, &y);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer, "wine.xpm", &x, &y);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer, "shrimp.xpm", &x, &y);
}

void	graphics(t_game *game, int height)
{
	int	width;

	while(height < game->mapheight)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer, game->barrier, width * 40, height * 40);
			width++;
		}
		height++;
	}
}

void	put_graphics(t_game *game)
{
	int	height;

	game->collectablecount = 0;
	height = 0;
	graphics(game, height);
}
