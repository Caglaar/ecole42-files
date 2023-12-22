

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*y;

	y = (char *)s;
	i = 0;
	while (i < n)
	{
		y[i] = '\0';
		i++;
	}
}
