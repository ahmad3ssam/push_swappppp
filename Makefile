SRCS = push_swap.c swap_op.c push_op.c rotate_op.c sort.c \
		sort_utils1.c sort_utils2.c ft_undup.c

CC = cc

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libpush.a
EXEC = push_swap

LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

MAKE = make

all: $(EXEC)

$(EXEC): $(NAME) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) push_swap.c $(NAME) $(LIBFT) $(PRINTF) -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

$(LIBFT):
	$(MAKE) -C ./libft

$(PRINTF):
	$(MAKE) -C ./ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf

re :fclean all

.PHONY: all clean fclean re
