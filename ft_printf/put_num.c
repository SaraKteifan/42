/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:34:54 by skteifan          #+#    #+#             */
/*   Updated: 2024/09/26 16:50:09 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_num(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	if (n < 10)
		count += put_char(n + 48);
	else
	{
		count += put_num(n / 10);
		count += put_num(n % 10);
	}
	return (count);
}
