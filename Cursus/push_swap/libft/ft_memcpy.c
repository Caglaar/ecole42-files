

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest;
	char		*sc;

	i = 0;
	dest = (char *)dst;
	sc = (char *)src;
	if (!sc && !dest)
		return (0);
	while (i < n)
	{
		dest[i] = sc[i];
		i++;
	}
	return (dest);
}
