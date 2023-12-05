#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h> //PARA DEFINIR NULL
# include <fcntl.h> //PARA OPERACIONES DE FICHEROS OPEN...
# include <unistd.h> //PARA READ

typedef struct s_data
{
	int		argc;
	char	**argv;
	char    **map;
	char	**map_flood_fill;
	int     number_rows;
	int		fd;
	int		flag_char;
	int		x_position_player;
	int		y_position_player;
}   t_data;

//000LIBFT1
int     ft_strlen(char *str);
char    *ft_strnstr(char *b, char *l, size_t len);
char	*ft_strdup(char *src);
//100CHECK
int		ft_check_parameters(t_data *d);
void	ft_check_characters(t_data *d);
int		ft_allow_chars(char *s, t_data *d);
//110INITIALIZE
void	ft_initialize_data(t_data *d);
//120ERRORMESSAGES
void	ft_error_messages(int message);
//200GNL
char	*ft_get_next_line(int fd);
//210GNLUTILS
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen_n(const char *s);
char	*ft_strchr(const char *s, int c);
//999FREE
void    ft_free_all(t_data *d);
//PRUEBA
void    ft_duplicate_map(t_data *d);
void    ft_flood_fill(int x, int y, t_data *d);
void    ft_print_map(t_data *d);
void    ft_locate_player(t_data *d);
void    ft_check_limits(t_data *d);

#endif