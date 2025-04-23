/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:42:53 by skteifan          #+#    #+#             */
/*   Updated: 2025/04/17 17:22:14 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_a(int argc, char **argv, t_stack **a)
{
	int		i;
	int		count;
	char	**input;
	t_stack	*node;

	if (argc == 2)
		input = ft_split(argv[1], ' ');
	else
		input = argv + 1;
	i = 0;
	count = count_argv(input);
	while (i < count)
	{
		node = create_node(ft_atoi(input[i]));
		add_node_at_end(a, node);
		i++;
	}
	if (argc == 2)
		free_input(input);
}
