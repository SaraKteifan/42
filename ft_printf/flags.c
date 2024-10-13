/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:25:04 by skteifan          #+#    #+#             */
/*   Updated: 2024/09/29 13:08:22 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	get_min_width(char *flags)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (flags[i] == ' ' || flags[i] == '-' || flags[i] == '+' || flags[i] == '#')
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

	i = 0;
	res = 0;
	while (flags[i] != '.' && flags[i])
		i++;
	if (flags[i] == '.')
		i++;
	while (flags[i] >= '0' && flags[i] <= '9')
	{
		res *= 10;
		res += (flags[i] - 48);
		i++;
	}
	return (res);
}

int	handle_flags(va_list ap, t_flags *flags, char c)
{
	int	count;

	if (c == 'c')
		count += put_char_flags(va_arg(ap, int), flags);
	if (c == 's')
		count += put_str_flags(va_arg(ap, char *), flags);
	if (c == 'p')
		count += put_ptr_flags(va_arg(ap, void *), flags);
	if (c == 'd' || c == 'i')
		count += put_num_flags(va_arg(ap, int), flags);
	if (c == 'u')
		count += put_unum_flags(va_arg(ap, unsigned int), flags);
	if (c == 'x')
		count += put_lhex_flags(va_arg(ap, unsigned int), flags);
	if (c == 'X')
		count += put_uhex_flags(va_arg(ap, unsigned int), flags);
	return (count);
}
