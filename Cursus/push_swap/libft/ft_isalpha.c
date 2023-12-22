

#include "libft.h"

int	ft_isalpha(int s)
{
	if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))
	{
		return (1);
	}
	return (0);
}
