
#include "push_swap.h"

int	check_sorted(t_stack **a)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp->next)
	{
		if(tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}

	return (0);
}

void	sort_3(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		swap_a(a);
	if ((*a)->next->value > (*a)->next->next->value)
		r_rotate_a(a);
	if ((*a)->value > (*a)->next->value)
		swap_a(a);
	//printf("%d %d %d \n", (*a)->value, (*a)->next->value, (*a)->next->next->value);
}

void	sort_small_stack(t_stack **a, int count)
{
	if (count == 2)
	{
		if ((*a)->value > (*a)->next->value)
			swap_a(a);
	}
	else if (count == 3)
		sort_3(a);
	else if (count >= 4)
		printf("I cannot sort it yet\n");
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	count;
	(void)b;

	//printf("%d %d %d \n", (*a)->value, (*a)->next->value, (*a)->next->next->value);
	count = count_stack(a);
	if (!check_sorted(a))
		return ;
	if (count <= 5)
		sort_small_stack(a, count);
	else
		printf("I cannot sort it yet\n");
}
