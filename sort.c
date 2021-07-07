#include "push_swap.h"
#include <unistd.h>

void	sa_rule(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->node->number;
	stack_a->node->number = stack_a->node->next->number;
	stack_a->node->next->number = temp;
	write(1, "sa\n", 4);
}

void	rra_rule(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->node->number;
	stack_a->node->number = stack_a->node->prev->number;
	stack_a->node->prev->number = stack_a->node->next->number;
	stack_a->node->next->number = temp;
	write(1, "rra\n", 5);
}

void	ra_rule(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->node->number;
	stack_a->node->number = stack_a->node->next->number;
	stack_a->node->next->number = stack_a->node->prev->number;
	stack_a->node->prev->number = temp;
	write(1, "ra\n", 4);
}

void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_a;

	node_a = stack_a->node;
	if (node_a->number > node_a->next->number
		&& node_a->number < node_a->prev->number)
		sa_rule(stack_a);
	if (node_a->number > node_a->next->number
		&& node_a->next->number > node_a->prev->number)
	{
		sa_rule(stack_a);
		rra_rule(stack_a);
	}
	if (node_a->number > node_a->next->number
		&& node_a->next->number < node_a->prev->number)
		ra_rule(stack_a);
	if (node_a->number < node_a->next->number
		&& node_a->next->number > node_a->prev->number)
	{
		sa_rule(stack_a);
		ra_rule(stack_a);
	}
	if (node_a->number < node_a->next->number
		&& node_a->next->number > node_a->prev->number)
		rra_rule(stack_a);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		sort_three(stack_a, stack_b);
}
