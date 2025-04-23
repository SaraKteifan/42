/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:34:44 by skteifan          #+#    #+#             */
/*   Updated: 2025/04/17 15:34:44 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(int argc, char **input)
{
	if (argc == 2)
		free_input(input);
	write(1, "Error\n", 6);
	exit(0);
}

void	free_input(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		free(input[i++]);
	free(input);
}

int	count_argv(char **input)
{
	int	i;

	i = 0;
	if (!input)
		return (0);
	while (input[i])
		i++;
	return (i);
}
