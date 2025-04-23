/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:00:35 by skteifan          #+#    #+#             */
/*   Updated: 2025/04/21 16:00:37 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **s1, t_stack **s2)
{
	t_stack	*tmp;

	if (!(*s1))
		return ;
	tmp = (*s1);
	(*s1) = (*s1)->next;
	tmp->next = (*s2);
	(*s2) = tmp;
}

void	push_a(t_stack **s1, t_stack **s2)
{
	push(s1, s2);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **s1, t_stack **s2)
{
	push(s1, s2);
	write(1, "pb\n", 3);
}
