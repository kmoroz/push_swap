/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 12:30:25 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/13 16:38:36 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compare(t_stack *stack, t_node *first,
	t_node *second, t_node *third)
{
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

void	sort_three(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->node;
	second = first->next;
	third = second->next;
	if (!is_sorted(stack->node))
		compare(stack, first, second, third);
}
