/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:19:24 by skteifan          #+#    #+#             */
/*   Updated: 2024/11/12 12:03:58 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flags_exist(t_flags	*flags)
{
	if (flags->min != 0 || flags->precision != 0 || flags->left != 0
		|| flags->zero != 0 || flags->form != 0 || flags->space != 0
		|| flags->plus != 0)
		return (1);
	return (0);
}

t_flags	*flags_set(char *s)
{
	t_flags	*flags;

	if (s == NULL)
		return (NULL);
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->min = get_min_width(s);
	flags->precision = get_precision(s);
	flags->left = in_set(s, '-');
	flags->zero = get_zero(s);
	flags->form = in_set(s, '#');
	flags->space = in_set(s, ' ');
	flags->plus = in_set(s, '+');
	if (!check_flags_exist(flags))
	{
		free(flags);
		free(s);
		return (NULL);
	}
	free(s);
	return (flags);
}

int	handle_flags(va_list ap, t_flags *flags, char c)
{
	int	count;

	count = 0;
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
	if (c == '%')
		count += put_char('%');
	return (count);
}
