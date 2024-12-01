#include "ft_printf.h"

static int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count = ft_print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count = ft_print_ptr(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count = ft_print_int(va_arg(ap, int));
	else if (specifier == 'u')
		count = ft_print_int(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count = ft_print_hex((unsigned int)va_arg(ap, unsigned long),
				specifier);
	else if (specifier == '%')
		count = write(1, "%", 1);
	else
	{
		count += write(1, "%", 1);
		count += write(1, &specifier, 1);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
