/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:55:40 by skteifan          #+#    #+#             */
/*   Updated: 2024/09/26 12:07:48 by skteifan         ###   ########.fr       */
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

char	*flags_set(char *s)
{
	int		i;
	char	*flags;

	i = 0;
	while (!in_set("cspdiuxX%", s[i]))
		i++;
	flags = malloc(i + 1);
	i = 0;
	while (!in_set("cspdiuxX%", s[i]))
	{
		flags[i] = s[i];
		i++;
	}
	flags[i] = '\0';
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
	char	c;
	char	*flags;

	i = 0;
	flags = flags_set(s);
	while (!in_set("cspdiuxX%", s[i]))
		i++;
	if (flags[0] != '\0')
		count += handle_flags(ap, flags, s[i]);
	count += put_arg(ap, s[i]);
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
			count += handle_argument(va_list ap, &s[i++]);
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
