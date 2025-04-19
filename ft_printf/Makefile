NAME = libftprintf.a

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf \
	ft_putchar \
	ft_putstr \
	ft_putptr \
	ft_putnum \
	ft_putunum \
	ft_putlhex \
	ft_putuhex \
	ft_utils \
	ft_flags_bonus \
	ft_get_flags_bonus \
	ft_putchar_bonus \
	ft_putstr_bonus \
	ft_putptr_bonus \
	ft_putnum_bonus \
	ft_putunum_bonus \
	ft_putlhex_bonus \
	ft_putuhex_bonus

CFILES = $(FILES:%=%.c)

OFILES = $(FILES:%=%.o)

%.o: %.c
	$(COMPILER) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	ar -rcs $(NAME) $(OFILES)

all: $(NAME)

bonus: all

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
