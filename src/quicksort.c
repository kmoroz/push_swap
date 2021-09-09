/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quicksort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 12:27:33 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/09 12:28:14 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
