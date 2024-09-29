/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:19:24 by skteifan          #+#    #+#             */
/*   Updated: 2024/09/26 16:50:16 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	handle_alternate_form_flag(char c)
{
	if (c == 'x')
	{
		write(1, "0x", 2);
		return (2);
	}
	if (c == 'X')
	{
		write(1, "0X", 2);
		return (2);
	}
	return (0);
}

int	handle_space_flag(char c)
{
	if (c == 'i' || c == 'd')
	{
		write(1, " ", 1);
		return (1);
	}
	return (0);
}

int	handle_flags(va_list ap, char *flags, char c)
{
	int	count;

	count = 0;
	if (in_set(flags, '#'))
		count += handle_alternate_form_flag(c);
	if (in_set(flags, ' ') && !in_set(flags, '+'))
		count += handle_space_flag(c);
	if (in_set(flags, '+'))
		;
}
