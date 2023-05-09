#include "so_long.h"

void	init_game_struct(t_game *game)
{
	game->fd = 0;
	game->mapheight = 0;
	game->mapwidth = 0;
	game->playercount = 0;
	game->collcheck = 0;
	game->exitcount = 0;
	game->x_axis = 0;
	game->y_axis = 0;
	game->counter = 0;
	game->collectablecount = 0;
	game->map = NULL;
	game->floor = 0;
	game->wall = 0;
	game->player = 0;
	game->exit = 0;
	game->collectable = 0;
	game->blocker = 0;
	game->mlxpointer = 0;
	game->winpointer = 0;
}

int	exit_point(t_game *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free(game->mlxpointer);
	while (line < game->mapheight - 1)
		free(game->map[line++]);
	free(game->map);
	exit (0);
}

int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
	{
		printf("\n\033[1;31mError: Expected one argument\033[0m\n");
		exit(1);
	}
	game = (t_game *)malloc(sizeof(t_game));
	if (game == NULL)
		return (0);
	init_game_struct(game);
	read_map(game, argv);
	error_check(game);
	//check_rectangle(game);
	game->mlxpointer = mlx_init();
	game->winpointer = mlx_new_window(game->mlxpointer, (game->mapwidth * 50), (game->mapheight * 50), "so_long");
	put_images(game);
	put_graphics(game);
	mlx_key_hook(game->winpointer, controls, game);
	mlx_hook(game->winpointer, 17, 0, (void *)exit, 0);
	mlx_loop(game->mlxpointer);
}