#include "map.h"
#include "so_long.h"

/* allocating memory to create a tilemap with same size as **map */
t_tile  **alloc_tilemap(char **map)
{
    t_tile **tilemap;
    int i;

    tilemap = malloc(sizeof(t_tile *) * ft_table_rowcount(map) + 1);
    if (!tilemap)
        return (NULL);
    i = 0;
    while (map[i] != NULL)
    {
        tilemap[i] = malloc(sizeof(t_tile) * ft_strlen(*map) + 1);
        if (!tilemap[i]) /* same as if (tilemap == NULL)??*/
        {
            while (i >= 0)
                free(tilemap[i--]);
            return (NULL);
        }
        i++;
    }
    return (tilemap);
}

/* returns tiletype that corresponds with each identifier */
t_tiletype  id_tiletype(char identifier)
{
    if (identifier == '1')    /*could be else if´s? */
        return (WALL);
    if (identifier == 'C')
        return (COLLECTABLE);
    if (identifier == 'P')
        return (PLAYER);
    if (identifier == 'E')
        return (EXIT);
    if (identifier == 'H' || identifier == 'V')
        return (ENEMY);
    else if (identifier == 'F')
        return (FOLLOWER);
    return (EMPTY);             /*???*/
}

