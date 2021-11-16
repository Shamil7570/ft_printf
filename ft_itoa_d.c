
#include "ft_printf.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int	ft_nblen_d(int n)
{
	int	size_n;
	int	nb;

	nb = n;
	size_n = 0;
	if (nb <= 0)
		size_n++;
	while (nb)
	{
		size_n++;
		nb /= 10;
	}
	return (size_n);
}

int	ft_itoa_d(int n)
{
	int		size_n;
	char	result_str[12];

	size_n = ft_nblen_d(n);
	result_str[size_n] = '\0';
	if (n == -2147483648)
		return (write(1, ft_strcpy(result_str, "-2147483648"), 11));
	if (n < 0)
	{
		result_str[0] = '-';
		n = -n;
	}
	if (n == 0)
		result_str[0] = '0';
	while (n)
	{
		result_str[size_n - 1] = n % 10 + '0';
		size_n--;
		n /= 10;
	}
	return (write(1, result_str, ft_strlen(result_str)));
}
