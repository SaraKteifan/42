/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:34:29 by skteifan          #+#    #+#             */
/*   Updated: 2025/04/17 15:34:29 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *s)
{
	int	i;

	i = 0;
	if ((s[i] == '+') || (s[i] == '-'))
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_double(char **input)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = count_argv(input);
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_atoi(input[i]) == ft_atoi(input[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_input(int argc, char **argv)
{
	int		i;
	char	**input;

	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = argv + 1;
	i = 0;
	while (input[i])
	{
		if (!is_number(input[i]))
			display_error(argc, input);
		if (ft_atoi(input[i]) < INT_MIN || ft_atoi(input[i]) > INT_MAX)
			display_error(argc, input);
		i++;
	}
	if (check_double(input))
		display_error(argc, input);
	if (argc == 2)
		free_input(input);
}
