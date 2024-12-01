#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_int(long n);
int	ft_print_hex(unsigned long n, char specifier);
int	ft_print_ptr(void *ptr);

int	ft_printf(const char *format, ...);

#endif
