#include "cub3d.h"

static void	ft_leaks(void)
{
	system("leaks -q cub3d");
}

int main(int argc, char **argv)
{
	atexit(ft_leaks);
	t_data	d;

	d.argc = argc;
	d.argv = argv;
	if (ft_check_parameters(&d) != 1)
		ft_error_messages(1);
	ft_initialize_data(&d);
	ft_free_all(&d);

	return (0);
}