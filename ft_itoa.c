
#include "ft_printf.h"

int	ft_nblen(unsigned long n)
{
	int		len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_itoa(unsigned long n, char *p)
{
	if (n > 15)
	{
		ft_itoa(n / 16, p);
		ft_itoa(n % 16, p);
	}
	else
		write(1, &p[n], 1);
}

int	ft_decimal_u(va_list args)
{
	int		i;

	i = va_arg(args, unsigned int);
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (ft_itoa_u(i));
}

int	ft_decimal(va_list args)
{
	int		i;

	i = va_arg(args, int);
	return (ft_itoa_d(i));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}
