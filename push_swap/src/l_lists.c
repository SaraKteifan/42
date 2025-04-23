/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_lists.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:05:47 by skteifan          #+#    #+#             */
/*   Updated: 2025/04/21 15:32:11 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*n;

	n = malloc(sizeof(t_stack));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}

void	add_node_at_end(t_stack **stack, t_stack *node)
{
	t_stack	*ptr;

	if (node == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
		return ;
	}
	ptr = *stack;
	while (ptr)
	{
		if (ptr->next == NULL)
		{
			ptr->next = node;
			return ;
		}
		ptr = ptr->next;
	}
}

void	stack_clear(t_stack **s)
{
	t_stack	*tmp;

	if (*s == NULL)
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}

int	count_stack(t_stack **s)
{
	int	i;
	t_stack *tmp;

	i = 0;
	tmp = *s;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
