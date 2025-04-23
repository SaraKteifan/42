/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:34:37 by skteifan          #+#    #+#             */
/*   Updated: 2025/04/17 15:34:37 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		check_input(argc, argv);
		a = NULL;
		init_a(argc, argv, &a);
		b = NULL;
		sort_stack(&a, &b);
		stack_clear(&a);
		stack_clear(&b);
	}
	return (0);
}
