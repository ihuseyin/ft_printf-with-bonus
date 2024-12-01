#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	count;

	if (s == NULL)
		return (write(1, "(null)", 6));
	count = 0;
	while (*s)
	{
		count += write(1, s, 1);
		s++;
	}
	return (count);
}
