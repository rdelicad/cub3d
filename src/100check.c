#include "cub3d.h"

int	ft_check_parameters(t_data *d)
{
	if (d->argc == 2 && ft_strnstr(d->argv[1], ".cub", ft_strlen(d->argv[1])))
	{
		printf("ABRIENDO ARCHIVO...\n\n");//--------------------------------		ELIMINAR ESTA LINEA
		return (1);
	}
	else
	{
		printf("ERROR\tDATOS ERRONEOS\n");//--------------------------------		ELIMINAR ESTA LINEA
		return (-1);
	}
}

int	ft_allow_chars(char *s, t_data *d)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (d->flag_char == 0)
		{
			if (s[i] == 'N' || s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
				d->flag_char = 1;
			else if (s[i] != '0' && s[i] != '1')
				return (0);
		}
		else
		{
			if (s[i] != '0' && s[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_check_characters(t_data *d)
{
	int		r;
	char	*str;

	d->fd = open(d->argv[1], O_RDONLY);
	r = 0;
	while (r < d->number_rows)
	{
		str = ft_get_next_line(d->fd);
		if (!ft_allow_chars(str, d))
			ft_error_messages(2);
		r++;
		free (str);
	}
	close(d->fd);
}
