/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:34:22 by skteifan          #+#    #+#             */
/*   Updated: 2024/09/26 12:09:46 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_str(char *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
	{
		count += put_str("(null)");
		return (count);
	}
	while (s[i] != '\0')
		count += put_char(s[i++]);
	return (count);
}
