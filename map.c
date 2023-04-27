#include "so_long.h"

int  get_map_width(char *str)
{
    int	width;

	width = 0;
	while (str[width])
		width++;
	if (str[width - 1] == '\n')
		width--;
	return (width);
}

int	add_line(t_game *game, char *line)
{
	char **temp;
	int	i;

	if (!line)
		return (0);
	i = 0;
	game->mapheight++;
	temp = (char **)malloc(sizeof(t_game) * (game->mapheight + 1));
	temp[game->mapheight] = NULL;
	while (i < game->mapheight - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	//printf("%d\n", game->mapheight);
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	read_map(t_game *game, char **argv)
{
	char *mapreader;

	game->fd = open(argv[1], O_RDONLY);
	//printf("%d\n", game->fd);
	if (game->fd < 0)
		return (0);
	while (TRUE)
	{
		mapreader = get_next_line(game->fd);
		if (!(add_line(game, mapreader)))
			break ;
	}
	close(game->fd);
	game->mapwidth = get_map_width(game->map[0]);
	//printf("%d\n", game->mapwidth);
	//printf("%d\n", game->mapheight);
	return (1);
}