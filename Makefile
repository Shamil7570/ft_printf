
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_FILES = ft_itoa.c \
			ft_printf_utils.c \
			ft_printf.c \
			ft_itoa_d.c \
			ft_itoa_u.c
			
							
OBJ_FILES = $(SRC_FILES:.c=.o)

HEADER = ft_printf.h

RM = rm -rf

all:  $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME) : $(OBJ_FILES)
	ar crs $(NAME) $(OBJ_FILES)
clean:
	$(RM) $(OBJ_FILES)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re