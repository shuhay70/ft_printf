NAME = libft.a

SRCS = ft_printf.c \
		ft_putstr.c\
		ft_format_check.c\
		ft_putnbr_base.c\
		ft_putchar.c\
       

OBJS = $(SRCS:.c=.o)

HEADER = libft.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re