#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	pb_rule(t_stack *stack_a, t_stack *stack_b, t_node **head, int num)
{
	t_node	*current;
	t_node	*tail;

	current = *head;
	tail = (*head)->prev;
	if ((*head)->number == num)
	{
		put_num_on_stack((*head)->number, &stack_b->node);
		*head = (*head)->next;
		tail->next = *head;
		(*head)->prev = tail;
	}
	else
	{
		while (current->number != num)
			current = current->next;
		put_num_on_stack(current->number, &stack_b->node);
		current->prev->next = current->next;
		current->next->prev = current->prev;
	}
	stack_a->size--;
	stack_b->size++;
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

void	sort_three(t_stack *stack_a)
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

void	find_pivot(t_node **head, int *pivot)
{
	t_node	*fast;
	t_node	*slow;

	fast = (*head)->next;
	slow = *head;
	while (fast != *head && fast->next != *head)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	*pivot = slow->number;
}

void	traverse_a(t_stack *stack_a, t_stack *stack_b, int pivot, t_node **head)
{
	t_node	*temp;
	t_node	*tail;

	temp = *head;
	tail = (*head)->prev;
	while (temp)
	{
		if (temp->number < pivot)
		{
			pb_rule(stack_a, stack_b, head, temp->number);
			temp = *head;
			tail = (*head)->prev;
			if (temp == tail)
				break ;
		}
		else
		{
			if (temp == tail)
				break ;
			temp = temp->next;
		}
	}
}

// void	add_partition(t_stack *stack_a)
// {
// 	if (stack_a->size == 1)
// 		stack_a->node->is_sorted = 1;
// 	if (stack_a->size == 3)
// 		sort_three(stack_a);
// }

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;

	while (stack_a->size > 3)
	{
		find_pivot(&stack_a->node, &pivot);
		traverse_a(stack_a, stack_b, pivot, &stack_a->node);
	}
	//add_partition(stack_a);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		sort_three(stack_a);
	if (stack_a->size > 3)
		quicksort(stack_a, stack_b);
}
