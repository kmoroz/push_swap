/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 12:40:13 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/09 12:42:47 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

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
