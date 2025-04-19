/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:55:40 by skteifan          #+#    #+#             */
/*   Updated: 2024/11/12 14:38:44 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	handle_argument(va_list ap, char *flags_str, char c)
{
	int		count;
	t_flags	*flags;

	count = 0;
	flags = flags_set(flags_str);
	if (flags == NULL)
		count += put_arg(ap, c);
	else
	{
		count += handle_flags(ap, flags, c);
		free(flags);
	}
	return (count);
}

char	*get_flags_str(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (!in_set("cspdiuxX%", s[i]))
		i++;
	if (i == 0)
		return (NULL);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (!in_set("cspdiuxX%", s[i]))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	char	*flags_str;
	va_list	ap;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			flags_str = get_flags_str(&s[++i]);
			while (!in_set("cspdiuxX%", s[i]))
				i++;
			count += handle_argument(ap, flags_str, s[i++]);
		}
		else
			count += put_char(s[i++]);
	}
	va_end(ap);
	return (count);
}
