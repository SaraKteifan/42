/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:30:02 by skteifan          #+#    #+#             */
/*   Updated: 2024/11/12 12:21:11 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_lhex_with_precision(unsigned int n, int precision, int form, int len)
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
	if (form && n != 0)
		count += put_str("0x");
	count += put_lhex(n);
	return (count);
}

int	put_lhex_with_left(unsigned int n, t_flags *flags, int len)
{
	int	count;
	int	cond;

	count = 0;
	if (flags->precision == 0)
	{
		if (flags->form && n != 0)
			count += put_str("0x");
		count += put_lhex(n);
		while (flags->min-- > len)
			count += put_char(' ');
	}
	else
	{
		cond = which_is_bigger(flags->precision, len);
		count += put_lhex_with_precision(n, flags->precision, flags->form, len);
		while (flags->min-- > cond)
			count += put_char(' ');
	}
	return (count);
}

int	put_lhex_without_left(unsigned int n, t_flags *flags, int len)
{
	int	count;
	int	cond;

	count = 0;
	if (flags->precision == 0)
	{
		count += handle_zero_flag(flags, len);
		if (flags->form && n != 0)
			count += put_str("0x");
		count += put_lhex(n);
	}
	else
	{
		cond = which_is_bigger(flags->precision, len);
		while (flags->min-- > cond)
			count += put_char(' ');
		count += put_lhex_with_precision(n, flags->precision, flags->form, len);
	}
	return (count);
}

int	put_lhex_flags(unsigned int n, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	len = count_hex(n);
	if (flags->precision == -1 && n == 0)
		len = 0;
	if (flags->form && n != 0)
		len += 2;
	if (flags->min == 0)
		count += put_lhex_with_precision(n, flags->precision, flags->form, len);
	else
	{
		if (flags->left)
			count += put_lhex_with_left(n, flags, len);
		else
			count += put_lhex_without_left(n, flags, len);
	}
	return (count);
}
