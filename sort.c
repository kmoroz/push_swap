#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	pb_rule(t_stack *stack_a, t_stack *stack_b, t_node **head)
{
	t_node	*current;
	t_node	*tail;

	put_num_on_stack((*head)->number, &stack_b->node);
	stack_a->size--;
	stack_b->size++;
	current = *head;
	tail = (*head)->prev;
	*head = (*head)->next;
	tail->next = *head;
	(*head)->prev = tail;
	free(current);
	write(1, "pb\n", 4);
}

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

void	find_pivot(t_node **head, int *pivot, int size)
{
	int		index;
	t_node	*temp;

	index = size / 2;
	temp = *head;
	while (index)
	{
		index--;
		temp = temp->next;
	}
	*pivot = temp->number;
}

void	traverse_a(t_stack *stack_a, t_stack *stack_b, int pivot, t_node **head)
{
	t_node	*temp;
	t_node	*tail;

	temp = *head;
	tail = (*head)->prev;
	while (temp != tail)
	{
		if (temp->number < pivot)
		{
			pb_rule(stack_a, stack_b, head);
			temp = *head;
		}
		else
			temp = temp->next;
	}
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;

	find_pivot(&stack_a->node, &pivot, stack_a->size);
	traverse_a(stack_a, stack_b, pivot, &stack_a->node);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		sort_three(stack_a, stack_b);
	if (stack_a->size > 3)
		quicksort(stack_a, stack_b);
}
