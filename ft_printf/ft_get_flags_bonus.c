/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:02:38 by skteifan          #+#    #+#             */
/*   Updated: 2024/11/12 14:22:24 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_min_width(char *flags)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (flags[i] == ' ' || flags[i] == '-' || flags[i] == '+'
		|| flags[i] == '#' || flags[i] == '0')
		i++;
	while (flags[i] >= '0' && flags[i] <= '9')
	{
		res *= 10;
		res += (flags[i] - 48);
		i++;
	}
	return (res);
}

int	get_precision(char *flags)
{
	int	i;
	int	res;
	int	dot;

	i = 0;
	res = 0;
	dot = 0;
	while (flags[i] != '.' && flags[i])
		i++;
	if (flags[i] == '.')
	{
		i++;
		dot = 1;
	}
	while (flags[i] >= '0' && flags[i] <= '9')
	{
		res *= 10;
		res += (flags[i] - 48);
		i++;
	}
	if (res == 0 && dot == 1)
		return (-1);
	return (res);
}

int	get_zero(char *s)
{
	int	i;

	i = 0;
	while (!(s[i] > '0' && s[i] <= '9') && s[i] != '.' && s[i] != '\0')
	{
		if (s[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	handle_zero_flag(t_flags *flags, int len)
{
	int	count;

	count = 0;
	if (flags->zero == 1)
	{
		while (flags->min-- > len)
			count += put_char('0');
	}
	else
	{
		while (flags->min-- > len)
			count += put_char(' ');
	}
	return (count);
}
