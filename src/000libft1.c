#include "../include/cub3d.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strnstr(char *b, char *l, size_t len)
{
	size_t	p1;
	size_t	p2;

	p1 = 0;
	if (!*l)
		return (b);
	while (b[p1] && p1 < len)
	{
		p2 = 0;
		while (b[p1 + p2] && b[p1 + p2] == l[p2] && p1 + p2 < len)
		{
			if (l[p2 + 1] == '\0' && b[p1 + p2 + 1] == '\0')
				return (&b[p1]);
			p2++;
		}
		p1++;
	}
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		pos;

	pos = 0;
	str = NULL;
	str = (char *) malloc ((ft_strlen_n(src) + 1) * sizeof(char));
	if (str)
	{
		while (src[pos] && src[pos] != '\n')
		{
			str[pos] = src[pos];
			pos++;
		}
		str[pos] = '\0';
	}
	else
	{
		free(str);
		return (NULL);
	}
	return (str);
}
