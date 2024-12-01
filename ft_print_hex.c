#include "ft_printf.h"

int	ft_print_hex(unsigned long n, char specifier)
{
	int		count;
	char	*symbols;

	count = 0;
	if (specifier == 'X')
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n == 0 && count == 0)
	{
		return (write(1, "0", 1));
	}
	if (n > 15)
	{
		count += ft_print_hex(n / 16, specifier);
	}
	count += write(1, &symbols[n % 16], 1);
	return (count);
}
