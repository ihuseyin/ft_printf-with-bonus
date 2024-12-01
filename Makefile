CC=cc
CFLAGS=-Wall -Wextra -Werror -g

BONUS_DIR=./bonus

SRCS= ft_print_char.c ft_print_str.c ft_print_int.c \
      ft_print_hex.c ft_print_ptr.c ft_printf.c

BONUS_SRCS= $(BONUS_DIR)/ft_print_char_bonus.c $(BONUS_DIR)/ft_print_str_bonus.c \
	    $(BONUS_DIR)/ft_print_int_bonus.c $(BONUS_DIR)/ft_print_hex_bonus.c \
	    $(BONUS_DIR)/ft_print_ptr_bonus.c $(BONUS_DIR)/ft_printf_bonus.c \
	    $(BONUS_DIR)/ft_printf_utils_bonus.c

SRCS_INCLUDES= -I.
BONUS_INCLUDES= -I$(BONUS_DIR)

OBJS=$(SRCS:.c=.o)
BONUS_OBJS=$(BONUS_SRCS:.c=.o)

NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: fclean $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(SRCS_INCLUDES) -c $< -o $@

$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
