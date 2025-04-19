/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:26:29 by skteifan          #+#    #+#             */
/*   Updated: 2024/10/30 15:42:28 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_lhex(unsigned int n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n < 16)
		count += put_char(hex[n]);
	else
	{
		count += put_lhex(n / 16);
		count += put_lhex(n % 16);
	}
	return (count);
}
