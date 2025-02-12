NAME = minishell
LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = ./src

SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/utils/utils.c $(SRC_DIR)/utils/ft_split2.c \
		$(SRC_DIR)/execute/execute.c $(SRC_DIR)/execute/utils/utils.c $(SRC_DIR)/execute/pipex.c\
		$(SRC_DIR)/parse/parse.c \
		$(SRC_DIR)/tokens/init.c $(SRC_DIR)/tokens/get_token.c \
		$(SRC_DIR)/utils/linked_list.c \
		$(SRC_DIR)/signals.c

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