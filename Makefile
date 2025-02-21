NAME = push_swap
BONUS = checker

SRCS = push_swap.c utils.c utils2.c apply_movements.c movements.c stack_init.c algorithm.c cost.c utils3.c
OBJS = $(SRCS:.c=.o)

B_SRCS = checker_src/checker.c libft/get_next_line.c utils.c utils2.c apply_movements.c movements.c stack_init.c algorithm.c cost.c utils3.c
B_OBJS = $(B_SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

bonus: $(BONUS)

$(BONUS): $(B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(BONUS) $(B_OBJS) -L $(LIBFT_DIR) -lft

clean:
	rm -f $(OBJS) $(B_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
