/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   applying_instructions.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 14:00:06 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/13 16:22:56 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	apply_common_instructions(t_node *temp, t_stack *stack_a,
	t_stack *stack_b)
{
	if (temp->number == SS)
		ss_rule(stack_a, stack_b);
	if (temp->number == RR)
		rr_rule(&stack_a->node, &stack_b->node);
	if (temp->number == RRR)
		rrr_rule(&stack_a->node, &stack_b->node);
}

static void	apply_a_instructions(t_node *temp, t_stack *stack_a,
	t_stack *stack_b)
{
	if (temp->number == SA)
		sa_rule(stack_a);
	if (temp->number == PA)
		pa_rule(stack_a, stack_b, &stack_b->node);
	if (temp->number == RA)
		ra_rule(&stack_a->node);
	if (temp->number == RRA)
		rra_rule(&stack_a->node);
}

static void	apply_b_instructions(t_node *temp, t_stack *stack_a,
	t_stack *stack_b)
{
	if (temp->number == SB)
		sb_rule(stack_b);
	if (temp->number == PB)
		pb_rule(stack_a, stack_b, &stack_a->node);
	if (temp->number == RB)
		rb_rule(&stack_b->node);
	if (temp->number == RRB)
		rrb_rule(&stack_b->node);
}

void	apply_instructions(t_node *instructions_head,
	t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tail;
	t_node	*temp;

	if (instructions_head)
	{
		tail = instructions_head->prev;
		tail->next = NULL;
		temp = instructions_head;
		while (temp)
		{
			apply_a_instructions(temp, stack_a, stack_b);
			apply_b_instructions(temp, stack_a, stack_b);
			apply_common_instructions(temp, stack_a, stack_b);
			temp = temp->next;
		}
	}
}
