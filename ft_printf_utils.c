
#include "ft_printf.h"

int	ft_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str)
	{
		write(1, str, ft_strlen(str));
		return (ft_strlen(str));
	}
	write(1, "(null)", 6);
	return (6);
}

int	ft_hexadecimal(va_list args)
{
	unsigned long	n;
	char			*p;

	p = "0123456789abcdef";
	n = va_arg(args, unsigned long);
	if (n == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	else
		ft_itoa(n, p);
	return (ft_nblen(n) + 2);
}

int	ft_hexadecimal_x(va_list args, const char c)
{
	unsigned int	n;
	char			*p;
	char			*p2;

	p = "0123456789ABCDEF";
	p2 = "0123456789abcdef";
	n = va_arg(args, unsigned int);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		if (c == 'x')
		{
			ft_itoa(n, p2);
			return (ft_nblen(n));
		}
	}
	ft_itoa(n, p);
	return (ft_nblen(n));
}

int	ft_flag(const char *str, int i, va_list args)
{
	int	j;

	j = 0;
	if (str[i] == 'c')
		j = ft_char(args);
	else if (str[i] == 's')
		j = ft_str(args);
	else if (str[i] == 'p')
	{
		write(1, "0x", 2);
		j = ft_hexadecimal(args);
	}
	else if (str[i] == 'i' || str[i] == 'd')
		j = ft_decimal(args);
	else if (str[i] == 'u')
		j = ft_decimal_u(args);
	else if (str[i] == 'x' || str[i] == 'X')
		j = ft_hexadecimal_x(args, str[i]);
	else if (str[i] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (j);
}
//-fsanitize=address