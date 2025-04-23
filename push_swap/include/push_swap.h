/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skteifan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:34:56 by skteifan          #+#    #+#             */
/*   Updated: 2025/04/17 15:34:56 by skteifan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../lib/libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		is_number(char *s);
int		check_double(char **input);
void	check_input(int argc, char **argv);
void	display_error(int argc, char **input);
void	free_input(char **input);
int		count_argv(char **input);

t_stack	*create_node(int value);
void	add_node_at_end(t_stack **stack, t_stack *node);
void	stack_clear(t_stack **s);
int	count_stack(t_stack **s);

void	init_a(int argc, char **argv, t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);

void	swap(t_stack **s);
void	swap_a(t_stack **s);
void	swap_b(t_stack **s);
void	swap_a_b(t_stack **s1, t_stack **s2);
void	push(t_stack **s1, t_stack **s2);
void	push_a(t_stack **s1, t_stack **s2);
void	push_b(t_stack **s1, t_stack **s2);
void	rotate(t_stack **s);
void	rotate_a(t_stack **s);
void	rotate_b(t_stack **s);
void	rotate_a_b(t_stack **s1, t_stack **s2);
void	r_rotate(t_stack **s);
void	r_rotate_a(t_stack **s);
void	r_rotate_b(t_stack **s);
void	r_rotate_a_b(t_stack **s1, t_stack **s2);

#endif
