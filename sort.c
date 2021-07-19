#include "push_swap.h"
#include <unistd.h>
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

void	pb_rule(t_stack *stack_a, t_stack *stack_b, t_node **head, int num)
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
	write(1, "pb\n", 4);
}

void	pa_rule(t_stack *stack_a, t_stack *stack_b, t_node **head, int num)
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
	write(1, "pa\n", 4);
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

void	ra_rule(t_node **head)
{
	if (*head)
		*head = (*head)->next;
	write(1, "ra\n", 4);
}

void	sort_three(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->node;
	second = first->next;
	third = second->next;
	if (first->number > second->number
		&& first->number < third->number)
		sa_rule(stack);
	else if (first->number > second->number
		&& second->number > third->number)
	{
		sa_rule(stack);
		rra_rule(stack);
	}
	else if (first->number > second->number
		&& second->number < third->number)
		ra_rule(&stack->node);
	else if (first->number < second->number
		&& second->number > third->number
		&& first->number < third->number)
	{
		sa_rule(stack);
		ra_rule(&stack->node);
	}
	else if (first->number < second->number
		&& second->number > third->number)
		rra_rule(stack);
}

void	pick_median_of_three(int *pivot, int head_num, int middle, int tail)
{
	if (middle > head_num && middle > tail && tail < head_num)
		*pivot = head_num;
	else if (middle > head_num && middle > tail && tail > head_num)
		*pivot = tail;
	else if (middle < head_num && middle < tail && tail < head_num)
		*pivot = tail;
	else if (middle < head_num && middle < tail && tail > head_num)
		*pivot = head_num;
	else if (middle > head_num && middle < tail && tail > head_num)
		*pivot = middle;
	else if (middle < head_num && middle > tail && tail < head_num)
		*pivot = middle;
}

void	find_pivot(int size, t_node **head, int *pivot, t_node **partition)
{
	t_node	*fast;
	t_node	*slow;
	int		tail;
	int		middle;
	int		head_num;

	fast = (*head)->next;
	slow = *head;
	tail = (*head)->prev->number;
	head_num = (*head)->number;
	if (!*partition)
	{
		while (fast != *head && fast->next != *head)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
	}
	else
	{
		while (fast != *partition && fast->next != *partition)
		{
			fast = fast->next->next;
			slow = slow->next;
		}	
	}
	middle = slow->number;
	if (size == 2)
	{
		if (head_num < tail)
			*pivot = head_num;
		else
			*pivot = tail;
	}
	else
		pick_median_of_three(pivot, head_num, middle, tail);
}

int	vals_less_than_pivot_left(t_node **head, int pivot, int size)
{
	int		count;
	t_node	*temp;

	count = size;
	temp = *head;
	while (count)
	{
		if (temp->number < pivot)
			return (1);
		temp = temp->next;
		count--;
	}
	return (0);
}

int	vals_more_than_pivot_left(t_node **head, int pivot, int size)
{
	int		count;
	t_node	*temp;

	count = size;
	temp = *head;
	while (count)
	{
		if (temp->number > pivot)
			return (1);
		temp = temp->next;
		count--;
	}
	return (0);
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
			if (!vals_less_than_pivot_left(head, pivot, stack_a->size))
				break ;
		}
		else
		{
			if (temp == tail)
				break ;
			ra_rule(head);
			temp = *head;
		}
	}
}

void	traverse_b(t_stack *stack_a, t_stack *stack_b, int pivot, t_node **head)
{
	t_node	*temp;
	t_node	*tail;

	temp = *head;
	tail = (*head)->prev;
	while (temp)
	{
		if (temp->number > pivot)
		{
			pa_rule(stack_a, stack_b, head, temp->number);
			temp = *head;
			tail = (*head)->prev;
			if (!vals_more_than_pivot_left(head, pivot, stack_a->size))
				break ;
		}
		else
		{
			if (temp == tail)
				break ;
			ra_rule(head); //should be rb_rule
			temp = *head;
		}
	}
}

void	sort_two(t_stack *stack)
{
	t_node	**head;

	*head = stack->node;
	if ((*head)->number > (*head)->next->number)
		sa_rule(stack);
}

void	add_partition(t_stack *stack)
{
	t_node	*temp;

	temp = stack->node;
	stack->partition = stack->node;
	while (!temp->is_sorted)
	{
		temp->is_sorted = 1;
		stack->size--;
		temp = temp->next;
	}
}

int	is_sorted(t_node *stack_a)
{
	t_node	*temp;

	if (!stack_a)
		return (0);
	temp = stack_a;
	while (temp->next != stack_a)
	{
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;

	pivot = 0;
	while (stack_a->size > 3)
	{
		find_pivot(stack_a->size, &stack_a->node, &pivot, &stack_a->partition);
		traverse_a(stack_a, stack_b, pivot, &stack_a->node);
	}
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
		add_partition(stack_a);
	}
	// if (stack_a->size == 2)
	// 	sort_two(stack_a);
	while (stack_b->size > 1)
	{
		find_pivot(stack_b->size, &stack_b->node, &pivot, &stack_b->partition);
		traverse_b(stack_a, stack_b, pivot, &stack_b->node);
	}
	pa_rule(stack_a, stack_b, &stack_b->node, stack_b->node->number);
	stack_b->node = 0;
	if (!is_sorted(stack_a->node))
		quicksort(stack_a, stack_b);
}

void	print_stack(t_node **head)
{
	t_node	*tail;
	t_node	*temp;

	tail = (*head)->prev;
	tail->next = NULL;
	temp = *head;
	while (temp)
	{
		printf("%d\n", temp->number);
		temp = temp->next;
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		sort_three(stack_a);
	if (stack_a->size > 3)
	{
		if (is_sorted(stack_a->node))
			exit(0);
		quicksort(stack_a, stack_b);
	}
	print_stack(&stack_a->node);
}
