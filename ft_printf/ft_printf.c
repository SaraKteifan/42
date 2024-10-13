/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:55:40 by skteifan          #+#    #+#             */
/*   Updated: 2024/10/01 12:47:39 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_flags_exist(t_flags	*flags)
{
	if (flags->min != 0 || flags->precision != 0 || flags->left != 0
		|| flags->zero != 0 || flags->form != 0 || flags->space != 0
		|| flags->plus != 0)
		return (1);
	return (0);
}

t_flags	*flags_set(char *s)
{
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	i = 0;
	flags->min = get_min_width(s);
	flags->precision = get_precision(s);
	flags->left = in_set(s, '-');
	flags->zero = in_set(s, '0');
	flags->form = in_set(s, '#');
	flags->space = in_set(s, ' ');
	flags->plus = in_set(s, '+');
	if (!check_flags_exist(flags))
	{
		free (flags);
		return (NULL);
	}
	return (flags);
}

int	put_arg(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += put_char(va_arg(ap, int));
	if (c == 's')
		count += put_str(va_arg(ap, char *));
	if (c == 'p')
		count += put_ptr(va_arg(ap, void *));
	if (c == 'd' || c == 'i')
		count += put_num(va_arg(ap, int));
	if (c == 'u')
		count += put_unum(va_arg(ap, unsigned int));
	if (c == 'x')
		count += put_lhex(va_arg(ap, unsigned int));
	if (c == 'X')
		count += put_uhex(va_arg(ap, unsigned int));
	if (c == '%')
		count += put_char('%');
	return (count);
}

int	handle_argument(va_list ap, char *s)
{
	int		i;
	int		count;
	t_flags	*flags;

	i = 0;
	count = 0;
	flags = flags_set(s);
	while (!in_set("cspdiuxX%", s[i]))
		i++;
	if (flags == NULL)
		count += put_arg(ap, s[i]);
	else
		count += handle_flags(ap, flags, s[i]);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			count += handle_argument(ap, (char *)&s[++i]);
			while (!in_set("cspdiuxX%", s[i]))
				i++;
			i++;
		}
		else
			count += put_char(s[i++]);
	}
	va_end(ap);
	return (count);
}
