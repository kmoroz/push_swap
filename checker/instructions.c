#include "checker.h"

void	sa_rule(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->node->number;
	stack_a->node->number = stack_a->node->next->number;
	stack_a->node->next->number = temp;
}
