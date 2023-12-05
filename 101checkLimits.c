#include "cub3d.h"

void    ft_duplicate_map(t_data *d)
{
    int r;

    r = 0;
    d->map_flood_fill = malloc (d->number_rows * sizeof(char *));
    while (r < d->number_rows)
    {
        d->map_flood_fill[r] = ft_strdup(d->map[r]);
        r++;        
    }
}

void    ft_flood_fill(int x, int y, t_data *d)
{
    printf("FLOOD FILL posicion X->%i Y->%i VALOR->%c", x, y, d->map_flood_fill[x][y]);
    if (x < 0 || y < 0 || x >= d->number_rows || !d->map_flood_fill[x][y]
            || d->map_flood_fill[x][y] == '1' || d->map_flood_fill[x][y] == '#')
            {
                printf ("\t\t CONDICION DE SALIDA\n");
                return ;
            }
    printf("\n");
    
    d->map_flood_fill[x][y] = '#';

    ft_flood_fill(x - 1, y, d);
    ft_flood_fill(x + 1, y, d);
    ft_flood_fill(x, y - 1, d);
    ft_flood_fill(x, y + 1, d);
}

void    ft_print_map(t_data *d)
{
    int r;

    r = 0;
    while (r < d->number_rows)
    {
        printf("%s\n", d->map_flood_fill[r]);
        r++;
    }
}

void    ft_locate_player(t_data *d)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x < d->number_rows)
    {
        while (d->map[x][y])
        {
            if (d->map[x][y] == 'N' || d->map[x][y] == 'S'
                    || d->map[x][y] == 'E' || d->map[x][y] == 'W')
                    {
                        d->x_position_player = x;
                        d->y_position_player = y;
                        return ;
                    }
            y++;
        }
        y = 0;
        x++;
    }
}

void    ft_check_limits(t_data *d)
{
    ft_duplicate_map(d);
    ft_locate_player(d);
    printf("POSICION JUGADOR X -> %i Y -> %i\n", d->x_position_player, d->y_position_player);
    ft_flood_fill(d->x_position_player, d->y_position_player, d);
    ft_print_map(d);
}