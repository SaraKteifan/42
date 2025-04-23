/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:13:50 by skteifan          #+#    #+#             */
/*   Updated: 2025/04/21 16:24:24 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack **s)
{
	t_stack	*tmp;

	if (!(*s) || !((*s)->next))
		return ;
	tmp = (*s);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*s);
	(*s) = tmp->next;
	tmp->next = NULL;
}

void	r_rotate_a(t_stack **s)
{
	r_rotate(s);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **s)
{
	r_rotate(s);
	write(1, "rrb\n", 4);
}

void	r_rotate_a_b(t_stack **s1, t_stack **s2)
{
	r_rotate(s1);
	r_rotate(s2);
	write(1, "rrr\n", 4);
}
