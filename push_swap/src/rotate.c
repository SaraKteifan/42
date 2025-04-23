/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:00:40 by skteifan          #+#    #+#             */
/*   Updated: 2025/04/21 16:29:38 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **s)
{
	t_stack	*tmp;

	if (!(*s) || !((*s)->next))
		return ;
	tmp = (*s);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*s);
	tmp = tmp->next;
	(*s) = (*s)->next;
	tmp->next = NULL;
}

void	rotate_a(t_stack **s)
{
	rotate(s);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **s)
{
	rotate(s);
	write(1, "rb\n", 3);
}

void	rotate_a_b(t_stack **s1, t_stack **s2)
{
	rotate(s1);
	rotate(s2);
	write(1, "rr\n", 3);
}
