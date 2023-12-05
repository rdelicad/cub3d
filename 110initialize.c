 #include "cub3d.h"

void	ft_number_rows(t_data *d)
{
	int	rows;
	char	*str;

	d->fd = open(d->argv[1], O_RDONLY);
	rows = 0;
	str = ft_get_next_line(d->fd);
	while (str != NULL)
	{
		//printf("STR -> %sLEN -> %i\n", str, ft_strlen(str));		//--------------------------------		ELIMINAR ESTA LINEA
		rows++;
		free (str);
		str = ft_get_next_line(d->fd);
	}
	free (str);
	d->number_rows = rows;
	//printf("NUMERO DE FILAS -> %i\n", d->number_rows);			//--------------------------------		ELIMINAR ESTA LINEA
	close(d->fd);
}

void	ft_liberate_map(t_data *d)
{
	int	r;

	r = 0;
	while (r < d->number_rows)
	{
		if (d->map[r] != NULL)
			free(d->map[r]);
		r++;
	}
}

void	ft_create_map(t_data *d)
{
	int		r;
	char	*str;

	d->fd = open(d->argv[1], O_RDONLY);
	r = 0;
	d->map = malloc (d->number_rows * sizeof (char *));
	if (!d->map)
		exit (1);
	while (r < d->number_rows)
	{
		d->map[r] = NULL;
		str = ft_get_next_line(d->fd);
		d->map[r] = ft_strdup(str);
		printf("%s\n", d->map[r]);					//--------------------------------		ELIMINAR ESTA LINEA
		r++;
		free(str);
	}
	close(d->fd);
	printf("\nMAPA CREADO CORRECTAMENTE\n");			//--------------------------------		ELIMINAR ESTA LINEA
}

void	ft_initialize_data(t_data *d)
{
	d->flag_char = 0;
	d->number_rows = 0;
	d->x_position_player = -1;
	d->y_position_player = -1;
	d->map = NULL;
	ft_number_rows(d);
	ft_check_characters(d);
	ft_create_map(d);
	ft_check_limits(d);
	
}