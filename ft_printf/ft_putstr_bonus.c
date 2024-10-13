/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:41:42 by skteifan          #+#    #+#             */
/*   Updated: 2024/10/02 17:17:57 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str_pre(char *s, int min, int pre)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0' && i < pre)
		count += put_char(s[i++]);
	return (count);
}

int	put_str_flags(char *s, t_flags *flags)
{
	int	count;
	int	i;

	if (flags->min == 0)
	{
		if (precision == 0)
			count += put_str(s);
		else
			count += put_str_pre(s, min, precision);
	}
	else
	{
			if(in_set(flags, '-'))
			{
				if (precision == 0)
				count += put_str(s);
				while (min-- > 1)
					count =+ put_char(' ');
			}
			else
			{
				while (min-- > 1)
					count =+ put_char(' ');
				count += put_char(c);
			}
	}
	return (count);
}
