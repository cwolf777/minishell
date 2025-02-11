NAME = minishell
LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJS_DIR = objs
SRC_DIR = ./src

SRCS =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/utils/utils.c $(SRC_DIR)/utils/ft_split2.c \
		$(SRC_DIR)/execute/execute.c $(SRC_DIR)/execute/utils/utils.c $(SRC_DIR)/execute/pipex.c\
		$(SRC_DIR)/parse/parse.c \
		$(SRC_DIR)/tokens/init.c $(SRC_DIR)/tokens/get_token.c \
		$(SRC_DIR)/utils/linked_list.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)
LIBS = -I$(LIBFT_DIR) -I./include
CC = cc
CFLAGS = -Wall -Werror -Wextra $(LIBS)

all: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -lreadline

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -f $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re