#include "so_long.h"

void	init_game_struct(t_game *game)
{
	game->fd = 0;
	game->mapheight = 0;
	game->mapwidth = 0;
	game->playercount = 0;
	game->columncount = 0;
	game->exitcount = 0;
	game->x_axis = 0;
	game->y_axis = 0;
	game->counter = 0;
	game->collectablecount = 0;
	game->map = NULL;
	game->floor = 0;
	game->barrier = 0;
	game->player = 0;
	game->exit = 0;
	game->collectable = 0;
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
	//int	width = get_map_width(argv[1]);

	if (argc != 2)
		return (0);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (0);
	init_game_struct(game);
	//printf("%d\n", width);
	//add_line(game, argv[1]);
	read_map(game, argv);
	/*errors fxn*/
	game->mlxpointer = mlx_init();
	game->winpointer = mlx_new_window(game->mlxpointer, (game->mapwidth * 40), (game->mapheight * 40), "solong");
}