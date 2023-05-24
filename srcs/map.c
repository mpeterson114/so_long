#include "so_long.h"

void    check_extension(char **argv)
{
    char *file_ext;

    file_ext = ft_strrchr(argv[1], '.');
    if (!file_ext || ft_strncmp(file_ext + 1, "ber", ft_strlen(argv[1])) != 0)
    {
        printf("\n\033[1;31mError: File type must be '.ber'\033[0m\n");
        exit(1);
    }
}

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
	temp = (char **)malloc(sizeof(char *) * (game->mapheight + 1));
	temp[game->mapheight] = NULL;
	while (i < game->mapheight - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	read_map(t_game *game, char **argv)
{
	char *mapreader;

	check_extension(argv);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		printf("\n\033[1;31mError, unable to open map\033[0m\n");
		exit_point(game);
	}
	while (TRUE)
	{
		mapreader = get_next_line(game->fd);
		if (!(add_line(game, mapreader)))
			break ;
	}
	if (game->mapheight == 0 && game->mapwidth == 0)
	{
		printf("\n\033[1;31mError, map is empty\033[0m\n");
		exit_point(game);
	}
	game->mapwidth = get_map_width(game->map[0]);
	close(game->fd);
	return (1);
}