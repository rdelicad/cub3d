#include "../include/cub3d.h"

void    ft_free_all(t_data *d)
{
    int r;

    r = 0;
    while (r < d->number_rows)
    {
        if (d->map[r])
            free(d->map[r]);
        if (d->map_flood_fill[r])
            free(d->map_flood_fill[r]);
        r++;
    }
    free (d->map);
    free (d->map_flood_fill);
}