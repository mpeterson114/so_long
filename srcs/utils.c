/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:55:43 by mpeterso          #+#    #+#             */
/*   Updated: 2023/05/23 11:55:44 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	int	length;

	length = ft_strlen(s);
	while (length >= 0)
	{
		if ((unsigned char)s[length] == (unsigned char)c)
			return ((char *)s + length);
		length--;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0 || (!s1 && !s2))
	{
		return (0);
	}
	while (i < n -1 && (s1[i] == s2[i]) && s1[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*xpm_check(t_game *game, char *str)
{
	void *img;
	int pix;

	pix = 50;
	img = mlx_xpm_file_to_image(game->mlxpointer, str, &pix, &pix);
	if (!img)
	{
		printf("\n\033[1;31mError: .xpm issue\033[0m\n");
		exit_point(game);
	}
	return(img);
}

void	copy_map(char **copy, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->mapheight)
	{
		copy[y] = (char *)malloc(sizeof(char) * game->mapwidth);
		y++;
	}
	y = 0;
	while (y < game->mapheight)
	{
		x = 0;
		while(x < game->mapwidth)
		{
			copy[y][x] = game->map[y][x];
			x++;
		}
		y++;
	}
}
