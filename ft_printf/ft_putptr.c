/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:26:45 by skteifan          #+#    #+#             */
/*   Updated: 2024/10/01 12:57:33 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_address(unsigned long long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n < 16)
		count += put_char(hex[n]);
	else
	{
		count += put_address(n / 16);
		count += put_address(n % 16);
	}
	return (count);
}

int	put_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += put_str("(nil)");
		return (count);
	}
	count += put_str("0x");
	count += put_address((unsigned long long) ptr);
	return (count);
}
