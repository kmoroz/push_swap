#include "checker.h"
#include <stdlib.h>

void	put_num_on_stack_reversed(int num, t_node **head)
{
	t_node	*tail;
	t_node	*new_node;

	new_node = ft_lstnew(num);
	if (!*head)
	{
		*head = new_node;
		tail = new_node;
		tail->next = *head;
		tail->prev = *head;
	}
	else
	{
		tail = (*head)->prev;
		new_node->next = *head;
		new_node->prev = tail;
		(*head)->prev = new_node;
		*head = new_node;
		tail->next = *head;
	}
}

void	sa_rule(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->node->number;
	stack_a->node->number = stack_a->node->next->number;
	stack_a->node->next->number = temp;
}

void	sb_rule(t_stack *stack_b)
{
	int	temp;

	temp = stack_b->node->number;
	stack_b->node->number = stack_b->node->next->number;
	stack_b->node->next->number = temp;
}

void	ss_rule(t_stack *stack_a, t_stack *stack_b)
{
	sa_rule(stack_a);
	sb_rule(stack_b);
}

void	pa_rule(t_stack *stack_a, t_stack *stack_b, t_node **head)
{
	t_node	*current;
	t_node	*tail;
	t_node	*next_head;

	current = *head;
	next_head = (*head)->next;
	tail = (*head)->prev;
	put_num_on_stack_reversed((*head)->number, &stack_a->node);
	free(current);
	*head = next_head;
	tail->next = *head;
	(*head)->prev = tail;
	stack_a->size++;
	stack_b->size--;
}

void	pb_rule(t_stack *stack_a, t_stack *stack_b, t_node **head)
{
	t_node	*current;
	t_node	*tail;

	current = *head;
	tail = (*head)->prev;
	put_num_on_stack_reversed((*head)->number, &stack_b->node);
	*head = (*head)->next;
	tail->next = *head;
	(*head)->prev = tail;
	stack_a->size--;
	stack_b->size++;
	free(current);
	if (stack_a->size == 0)
		stack_a->node = NULL;
}

void	ra_rule(t_node **head)
{
	if (*head)
		*head = (*head)->next;
}

void	rb_rule(t_node **head)
{
	if (*head)
		*head = (*head)->next;
}

void	rr_rule(t_node **head_a, t_node **head_b)
{
	ra_rule(head_a);
	rb_rule(head_b);
}

void	rra_rule(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
}

void	rrb_rule(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
}

void	rrr_rule(t_node **head_a, t_node **head_b)
{
	rra_rule(head_a);
	rra_rule(head_b);
}
