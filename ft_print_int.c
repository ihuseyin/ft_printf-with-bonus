#include "ft_printf.h"

int	ft_print_int(long n)
{
	int		count;
	char	digit;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		count += ft_print_int(n / 10);
	}
	digit = (n % 10) + 48;
	count += write(1, &digit, 1);
	return (count);
}
