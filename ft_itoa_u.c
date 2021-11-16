
#include "ft_printf.h"

static int	ft_nblen_u(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int	ft_itoa_u(unsigned int n)
{
	int		i;
	char	result_str[12];

	i = ft_nblen_u(n);
	result_str[i] = '\0';
	while (n)
	{
		result_str[i - 1] = n % 10 + '0';
		i--;
		n /= 10;
	}
	return (write(1, result_str, ft_strlen(result_str)));
}
