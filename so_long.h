/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:55:47 by mpeterso          #+#    #+#             */
/*   Updated: 2023/05/23 13:31:23 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
//look up libraries

typedef struct s_game
{
    int fd;
    int mapheight;
    int mapwidth;
    int playercount;
    int c_count;
    int exitcount;
    int player_x;
    int player_y;
    int c_check;
    int e_check;
    int x_axis;
    int y_axis;
    int moves_count;
    int c_remaining;

    char    **map;

    void    *floor;
    void    *wall;
    void    *player;
    void    *exit;
    void    *collectable;
    void    *blocker;
    void    *mlxpointer;
    void    *winpointer;
}   t_game;

typedef enum e_bool
{
    TRUE = 1,
    FALSE = 0,
}   t_bool;

/*typedef struct s_vector
{
    int x;
    int y;
}   t_vector;
*/

int  get_map_width(char *str);
int	add_line(t_game *game, char *line);
int	read_map(t_game *game, char **argv);
void    character_valid(t_game *game);
void    error_check(t_game *game);
void	place_player(t_game *game, int height, int width);
void	place_collectable(t_game *game, int height, int width);
void    put_images(t_game *game);
void    graphics(t_game *game, int height);
void	put_graphics(t_game *game);
int	exit_point(t_game *game);
int controls(int command, t_game *game);
void check_rectangle(t_game *game);
char	*ft_strrchr(const char *s, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void    check_extension(char **argv);
void	*xpm_check(t_game *game, char *str);
void	copy_map(char **copy, t_game *game);
void    check_route(char **copy, t_game *game);



#endif