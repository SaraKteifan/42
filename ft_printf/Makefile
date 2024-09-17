NAME = libftprintf.a

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf

CFILES = $(FILES:%=%.c)

OFILES = $(FILES:%=%.o)

%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re