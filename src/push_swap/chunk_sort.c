/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:41:14 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/09 12:49:30 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	move_closest_to_top(t_stack *stack_a, t_node **head_a)
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
	else if (count_from_bottom > count_from_top
		|| count_from_bottom == count_from_top)
	{
		while (count_from_top)
		{
			ra_rule(&stack_a->node);
			count_from_top--;
		}
	}
}

int	move_top_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_limit)
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
		if (move_top_to_b(stack_a, stack_b, chunk_limit))
		{
			chunk_limit += chunk_step;
			i = stack_a->size;
		}
	}
	stack_a->node = NULL;
	while (stack_b->size)
		traverse_b(stack_a, stack_b, &stack_b->node);
}
