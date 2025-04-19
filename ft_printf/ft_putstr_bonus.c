/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:41:42 by skteifan          #+#    #+#             */
/*   Updated: 2024/11/12 12:05:02 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str_with_precision(char *s, int precision)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (precision == -1)
		return (0);
	while (s[i] != '\0' && i < precision)
		count += put_char(s[i++]);
	return (count);
}

int	put_str_with_left(char *s, t_flags *flags, int len)
{
	int	count;

	count = 0;
	if (flags->precision == 0 || len < flags->precision)
	{
		count += put_str(s);
		while (flags->min-- > len)
			count += put_char(' ');
	}
	else
	{
		count += put_str_with_precision(s, flags->precision);
		if (flags->precision == -1)
			flags->precision++;
		while (flags->min-- > flags->precision)
			count += put_char(' ');
	}
	return (count);
}

int	put_str_without_left(char *s, t_flags *flags, int len)
{
	int	count;

	count = 0;
	if (flags->precision == 0 || len < flags->precision)
	{
		while (flags->min-- > len)
			count += put_char(' ');
		count += put_str(s);
	}
	else
	{
		if (flags->precision == -1)
			flags->precision++;
		while (flags->min-- > flags->precision)
			count += put_char(' ');
		if (flags->precision == 0)
			flags->precision--;
		count += put_str_with_precision(s, flags->precision);
	}
	return (count);
}

char	*handle_null_str(t_flags *flags)
{
	if (flags->precision > 0 && flags->precision < 6)
		flags->precision = -1;
	return ("(null)");
}

int	put_str_flags(char *s, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	if (s == NULL)
		s = handle_null_str(flags);
	len = strlength(s);
	if (flags->min == 0)
	{
		if (flags->precision == 0)
			count += put_str(s);
		else
			count += put_str_with_precision(s, flags->precision);
	}
	else
	{
		if (flags->left)
			count += put_str_with_left(s, flags, len);
		else
			count += put_str_without_left(s, flags, len);
	}
	return (count);
}
