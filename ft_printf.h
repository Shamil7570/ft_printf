
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_char(va_list args);
int			ft_str(va_list args);
int			ft_flag(const char *str, int i, va_list args);
int			ft_printf(const char *str, ...);
size_t		ft_strlen(const char *str);
void		ft_itoa(unsigned long n, char *p);
int			ft_hexadecimal(va_list args);
int			ft_hexadecimal_x(va_list args, const char c);
int			ft_itoa_d(int n);
int			ft_itoa_u(unsigned int n);
int			ft_decimal(va_list args);
int			ft_decimal_u(va_list args);
int			ft_nblen(unsigned long n);

#endif
