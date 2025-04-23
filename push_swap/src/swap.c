/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:00:47 by skteifan          #+#    #+#             */
/*   Updated: 2025/04/21 16:00:48 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s)
{
	t_stack	*tmp;

	if (!(*s && (*s)->next))
		return ;
	tmp = (*s)->next;
	(*s)->next = (*s)->next->next;
	tmp->next = (*s);
	(*s) = tmp;
}

void	swap_a(t_stack **s)
{
	swap(s);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **s)
{
	swap(s);
	write(1, "sb\n", 3);
}

void	swap_a_b(t_stack **s1, t_stack **s2)
{
	swap(s1);
	swap(s2);
	write(1, "ss\n", 3);
}
