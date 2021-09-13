/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 12:40:13 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/10 14:31:57 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
		sort_three(stack_a);
	else
		quicksort(stack_a, stack_b);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a->node))
		exit(free_node(&stack_a->node, stack_a->size));
	if (stack_a->size <= SMALL_STACK)
		sort_small(stack_a, stack_b);
	if (stack_a->size > SMALL_STACK)
		chunk_sort(stack_a, stack_b);
}
