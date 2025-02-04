NAME = minishell
LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = ./src
SRCS =	$(SRC_DIR)/main.c $(SRC_DIR)/execute.c $(SRC_DIR)/pipex_utils.c
OBJS = $(SRCS:.c=.o)
LIBS = -I$(LIBFT_DIR) -I./include
CC = cc
CFLAGS = -Wall -Werror -Wextra $(LIBS)

all: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -lreadline

$(LIBFT):
	make -C $(LIBFT_DIR)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re