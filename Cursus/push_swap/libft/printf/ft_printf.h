

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	checkpoint(unsigned long long int x);
int	ft_point(unsigned long long int x, int a);
int	ft_hex(unsigned int a, char c);
int	ft_putnbr(long int nb);
int	ft_unnbr(unsigned int a);
int	ft_putchar(int c);
int	ft_string(char *s);
int	ft_flag(char *s, int i);
int	ft_format(va_list *arg, char c);
int	ft_printf(const char *str, ...);

#endif
