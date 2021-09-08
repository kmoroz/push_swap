#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

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
	write(1, "pb\n", 3);
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
	write(1, "pa\n", 3);
}

void	sa_rule(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->node->number;
	stack_a->node->number = stack_a->node->next->number;
	stack_a->node->next->number = temp;
	write(1, "sa\n", 3);
}

void	rra_rule(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
	write(1, "rra\n", 4);
}

void	rrb_rule(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
	write(1, "rrb\n", 4);
}

void	ra_rule(t_node **head)
{
	if (*head)
		*head = (*head)->next;
	write(1, "ra\n", 3);
}

void	rb_rule(t_node **head)
{
	if (*head)
		*head = (*head)->next;
	write(1, "rb\n", 3);
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
		rra_rule(&stack->node);
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
		rra_rule(&stack->node);
}

int	vals_less_than_pivot_left(t_node **head, int pivot, int size)
{
	int		count;
	t_node	*temp;
	int		result;

	count = size;
	temp = *head;
	result = 0;
	while (count)
	{
		if (temp->number < pivot)
			result++;
		temp = temp->next;
		count--;
	}
	return (result);
}

void	find_pivot(int size, t_node **head, int *pivot)
{
	int		count;
	t_node	*temp;

	count = size;
	temp = *head;
	while (count)
	{
		if (vals_less_than_pivot_left(head, temp->number, size) == 2)
			*pivot = temp->number;
		temp = temp->next;
		count--;
	}
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
			pb_rule(stack_a, stack_b, head);
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

void	sort_two(t_node	**head, t_stack *stack)
{
	if ((*head)->number > (*head)->next->number)
		sa_rule(stack);
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

int	find_stack_min(t_stack *stack_a, t_node **head_a)
{
	int		min;
	int		i;
	t_node	*temp;

	min = INT_MAX;
	i = stack_a->size;
	temp = *head_a;
	while (i)
	{
		if (min > temp->number)
			min = temp->number;
		temp = temp->next;
		i--;
	}
	return (min);
}

int	find_stack_max(t_stack *stack, t_node **head)
{
	int		max;
	int		i;
	t_node	*temp;

	max = INT_MIN;
	i = stack->size;
	temp = *head;
	while (i)
	{
		if (max < temp->number)
			max = temp->number;
		temp = temp->next;
		i--;
	}
	return (max);
}

int	get_chunk_number(t_stack *stack_a, t_node **head_a)
{
	int	chunk_step;
	int	max;
	int	min;

	max = find_stack_max(stack_a, head_a);
	min = find_stack_min(stack_a, head_a);
	if (stack_a->size <= 100)
		chunk_step = ((max - min) / 5) + 1;
	if (stack_a->size > 100)
		chunk_step = ((max - min) / 12) + 1;
	return (chunk_step);
}

int	count_chunk_elements(t_stack *stack_a, t_node **head_a, int chunk_limit)
{
	int		i;
	t_node	*temp;
	int		count;

	i = stack_a->size;
	temp = *head_a;
	count = 0;
	while (i)
	{
		if (temp->number < chunk_limit)
		{
			temp->is_in_chunk = 1;
			count++;
		}
		temp = temp->next;
		i--;
	}
	return (count);
}

int	count_ra_moves(t_stack *stack_a, t_node **head_a)
{
	int		i;
	int		count_from_top;
	t_node	*temp;

	i = stack_a->size / 2;
	count_from_top = 0;
	temp = *head_a;
	while (i)
	{
		if (temp->is_in_chunk)
			break ;
		count_from_top++;
		temp = temp->next;
		i--;
	}
	return (count_from_top);
}

int	count_rra_moves(t_stack *stack_a, t_node **head_a)
{
	int		i;
	int		count_from_bottom;
	t_node	*temp;

	i = stack_a->size / 2;
	count_from_bottom = 1;
	temp = (*head_a)->prev;
	while (i)
	{
		if (temp->is_in_chunk)
			break ;
		count_from_bottom++;
		temp = temp->prev;
		i--;
	}
	return (count_from_bottom);
}

void move_closest_to_top(t_stack *stack_a, t_node **head_a)
{
	int		count_from_top;
	int		count_from_bottom;

	count_from_top = count_ra_moves(stack_a, head_a);
	count_from_bottom = count_rra_moves(stack_a, head_a);
	if (count_from_top > count_from_bottom)
	{
		while (count_from_bottom)
		{
			rra_rule(&stack_a->node);
			count_from_bottom--;
		}
	}
	else if (count_from_bottom > count_from_top || count_from_bottom == count_from_top)
	{
		while (count_from_top)
		{
			ra_rule(&stack_a->node);
			count_from_top--;
		}
	}
}

int	move_to_top(t_stack *stack_a, t_stack *stack_b, int chunk_limit)
{
	int	i;

	i = count_chunk_elements(stack_a, &stack_a->node, chunk_limit);
	while (i)
	{
		move_closest_to_top(stack_a, &stack_a->node);
		pb_rule(stack_a, stack_b, &stack_a->node);
		i--;
	}
	return (1);
}

int is_in_first_half(t_stack *stack, t_node **head, int num)
{
	int		i;
	t_node	*temp;

	temp = *head;
	i = stack->size / 2;
	while (i)
	{
		if (temp->number == num)
			return (1);
		i--;
		temp = temp->next;
	}
	return (0);
}

void	traverse_b(t_stack *stack_a, t_stack *stack_b, t_node **head_b)
{
	int		max;

	max = find_stack_max(stack_b, head_b);
	if (is_in_first_half(stack_b, head_b, max))
	{
		while ((*head_b)->number != max)
			rb_rule(head_b);
		pa_rule(stack_a, stack_b, head_b);
	}
	else
	{
		while ((*head_b)->number != max)
			rrb_rule(head_b);
		pa_rule(stack_a, stack_b, head_b);
	}
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_limit;
	int	i;
	int	chunk_step;

	chunk_step = get_chunk_number(stack_a, &stack_a->node);
	chunk_limit = find_stack_min(stack_a, &stack_a->node) + chunk_step;
	i = stack_a->size;
	while (i)
	{
		if (move_to_top(stack_a, stack_b, chunk_limit))
		{
			chunk_limit += chunk_step;
			i = stack_a->size;
		}
	}
	stack_a->node = NULL;
	while (stack_b->size)
		traverse_b(stack_a, stack_b, &stack_b->node);
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;
	int	i;
	int	max_b;

	pivot = 0;
	while (stack_a->size > 3)
	{
		find_pivot(stack_a->size, &stack_a->node, &pivot);
		i = vals_less_than_pivot_left(&stack_a->node, pivot, stack_a->size);
		while (i)
		{
			if (stack_a->node->number < pivot)
			{
				pb_rule(stack_a, stack_b, &stack_a->node);
				i--;
			}
			else
				ra_rule(&stack_a->node);
		}
	}
	sort_three(stack_a);
	max_b = find_stack_max(stack_b, &stack_b->node);
	if (stack_b->node->number != max_b)
		rb_rule(&stack_b->node);
	while (stack_b->size)
		pa_rule(stack_a, stack_b, &stack_b->node);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		sort_three(stack_a);
	else
		quicksort(stack_a, stack_b);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= SMALL_STACK)
		sort_small(stack_a, stack_b);
	if (stack_a->size > SMALL_STACK)
	{
		if (is_sorted(stack_a->node))
			exit(0);
		chunk_sort(stack_a, stack_b);
	}
}
