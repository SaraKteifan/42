/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:48:00 by skteifan          #+#    #+#             */
/*   Updated: 2024/11/12 12:13:25 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	strlength(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	count_num(long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	count_hex(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

int	which_is_bigger(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}
