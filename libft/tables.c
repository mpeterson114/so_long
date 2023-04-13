#include <stdlib.h>
#include "libft.h"

/* counts number of rows in a 2D table */
int ft_table_rowcount(char **table)
{
    int count;

    count = 0;
    while (table[count])
        count++;
    return (count);
}

/* frees 2D table */
void    ft_free_table(char **table)
{
    int i;

    i = 0;
    while (table[i])
    {
        free(table[i]);
        i++;
    }
    free(table);
}
