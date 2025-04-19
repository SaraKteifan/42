/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:21:26 by skteifan          #+#    #+#             */
/*   Updated: 2024/11/12 12:15:53 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_plus_space_flags(int plus, int space)
{
	if (plus)
		put_char('+');
	else if (space)
		put_char(' ');
	return (1);
}

int	put_num_with_precision(long int n, t_flags *flags, int len)
{
	int	count;

	count = 0;
	if (flags->precision == -1 && n == 0)
		return (0);
	if ((flags->plus || flags->space) && n >= 0)
		count += handle_plus_space_flags(flags->plus, flags->space);
	if (n < 0)
	{
		count += put_char('-');
		n = -n;
	}
	while (len < flags->precision)
	{
		count += put_char('0');
		len++;
	}
	count += put_num(n);
	return (count);
}

int	put_num_with_left(long int n, t_flags *flags, int len)
{
	int	count;
	int	cond;

	count = 0;
	if (flags->precision == 0)
	{
		if ((flags->plus || flags->space) && n >= 0)
			count += handle_plus_space_flags(flags->plus, flags->space);
		count += put_num(n);
		while (flags->min-- > len)
			count += put_char(' ');
	}
	else
	{
		cond = which_is_bigger(flags->precision, len);
		count += put_num_with_precision(n, flags, len);
		while (flags->min-- > cond)
			count += put_char(' ');
	}
	return (count);
}

int	put_num_without_left(long int n, t_flags *flags, int len)
{
	int	count;
	int	cond;

	count = 0;
	if (flags->precision == 0)
	{
		if ((flags->plus || flags->space) && n >= 0)
			count += handle_plus_space_flags(flags->plus, flags->space);
		if (flags->zero && n < 0)
		{
			count += put_char('-');
			n = -n;
		}
		count += handle_zero_flag(flags, len);
		count += put_num(n);
	}
	else
	{
		cond = which_is_bigger(flags->precision, len);
		while (flags->min-- > cond)
			count += put_char(' ');
		count += put_num_with_precision(n, flags, len);
	}
	return (count);
}

int	put_num_flags(long int n, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	len = count_num(n);
	if (flags->precision == -1 && n == 0)
		len = 0;
	if ((flags->plus || flags->space) && n >= 0)
		len ++;
	if (n < 0 && flags->precision > 0)
		flags->precision++;
	if (flags->min == 0)
		count += put_num_with_precision(n, flags, len);
	else
	{
		if (flags->left)
			count += put_num_with_left(n, flags, len);
		else
			count += put_num_without_left(n, flags, len);
	}
	return (count);
}
