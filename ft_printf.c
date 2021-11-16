
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += 1;
			count += ft_flag(str, i, args);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>

int main(void)
{
	printf("%s %d %p %x\n", "mama", -2147483648, (void *)-1, 453);
	ft_printf("%s %d %p %x\n", "mama", 2147483647, (void *)-1, 453);
	printf("%s%%\n", "mama");
	ft_printf("%s%%\n", "mama");
	printf("%p\n", "647645");
	ft_printf("%p\n", "647645");
	printf("%d\n", 2147483647);
	ft_printf("%d\n", 2147483647);
	printf("%x\n", 453);
	ft_printf("%x\n", 453);
	printf(" %X\n ", 453000999);
	ft_printf("%X\n", 453000999);
}