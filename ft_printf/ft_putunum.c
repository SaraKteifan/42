/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:53:38 by skteifan          #+#    #+#             */
/*   Updated: 2024/09/26 12:00:15 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_unum(unsigned int n)
{
	int		count;

	count = 0;
	if (n < 10)
		count += put_char(n + 48);
	else
	{
		count += put_unum(n / 10);
		count += put_unum(n % 10);
	}
	return (count);
}
