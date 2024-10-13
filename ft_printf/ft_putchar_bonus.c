/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:22:14 by skteifan          #+#    #+#             */
/*   Updated: 2024/10/02 16:31:59 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char_flags(char c, t_flags *flags)
{
	int	count;

	if (flags->min == 0)
		count += put_char(c);
	else
	{
			if(flags->left)
			{
				count += put_char(c);
				while (flags->min-- > 1)
					count =+ put_char(' ');
			}
			else
			{
				while (flags->min-- > 1)
					count =+ put_char(' ');
				count += put_char(c);
			}
	}
	return (count);
}
