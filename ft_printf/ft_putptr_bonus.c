/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:41:42 by skteifan          #+#    #+#             */
/*   Updated: 2024/10/30 13:18:22 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_ptr(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (3);
	while (n > 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

int	put_ptr_flags(void *ptr, t_flags *flags)
{
	int	count;
	int	len;

	count = 0;
	len = count_ptr((unsigned long long) ptr) + 2;
	if (flags->min == 0)
		count += put_ptr(ptr);
	else
	{
		if (flags->left)
		{
			count += put_ptr(ptr);
			while (flags->min-- > len)
				count += put_char(' ');
		}
		else
		{
			while (flags->min-- > len)
				count += put_char(' ');
			count += put_ptr(ptr);
		}
	}
	return (count);
}
