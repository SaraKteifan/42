/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunum_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:58:38 by skteifan          #+#    #+#             */
/*   Updated: 2024/11/12 12:21:58 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unum_with_precision(unsigned int n, int precision, int len)
{
	int	count;

	count = 0;
	if (precision == -1 && n == 0)
		return (0);
	while (len < precision)
	{
		count += put_char('0');
		len++;
	}
	count += put_unum(n);
	return (count);
}

int	put_unum_with_left(unsigned int n, t_flags *flags, int len)
{
	int	count;
	int	cond;

	count = 0;
	if (flags->precision == 0)
	{
		count += put_unum(n);
		while (flags->min-- > len)
			count += put_char(' ');
	}
	else
	{
		cond = which_is_bigger(flags->precision, len);
		count += put_unum_with_precision(n, flags->precision, len);
		while (flags->min-- > cond)
			count += put_char(' ');
	}
	return (count);
}

int	put_unum_without_left(unsigned int n, t_flags *flags, int len)
{
	int	count;
	int	cond;

	count = 0;
	if (flags->precision == 0)
	{
		count += handle_zero_flag(flags, len);
		count += put_unum(n);
	}
	else
	{
		cond = which_is_bigger(flags->precision, len);
		while (flags->min-- > cond)
			count += put_char(' ');
		count += put_unum_with_precision(n, flags->precision, len);
	}
	return (count);
}

int	put_unum_flags(unsigned int n, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	len = count_num(n);
	if (flags->precision == -1 && n == 0)
		len = 0;
	if (flags->min == 0)
		count += put_unum_with_precision(n, flags->precision, len);
	else
	{
		if (flags->left)
			count += put_unum_with_left(n, flags, len);
		else
			count += put_unum_without_left(n, flags, len);
	}
	return (count);
}
