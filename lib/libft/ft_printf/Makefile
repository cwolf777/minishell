CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = 	ft_printf.c ft_print_char.c ft_print_str.c \
		ft_print_nbr.c ft_print_hexnbr.c ft_print_pointer.c \
		ft_print_unsignednbr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
