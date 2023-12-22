

#include "libft.h"

int	ft_isalnum(int y)
{
	if ((y >= 'a' && y <= 'z') || (y >= 'A' && y <= 'Z')
		|| (y >= '0' && y <= '9'))
	{
		return (1);
	}
	return (0);
}
