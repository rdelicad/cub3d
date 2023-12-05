#include "../include/cub3d.h"

void	ft_error_messages(int message)
{
	printf("ERROR\n");
	if (message == 1)
		printf("SE HA PRODUCIDO UN ERROR EN LA COMPROBACION PREVIA DEL FICHERO\n");
	else if (message == 2)
		printf("SE HAN ENCONTRADO CARACTERES INVALIDOS EN EL MAPA\n");
	else if (message == 3)
		printf("SE HA PRODUCIDO UN ERROR EN LA COMPROBACION DEL MURO\n");
	exit(1);
}