/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_b_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 13:35:14 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/13 13:40:39 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

void	sb_rule(t_stack *stack_b)
{
	int	temp;

	temp = stack_b->node->number;
	stack_b->node->number = stack_b->node->next->number;
	stack_b->node->next->number = temp;
}

void	pb_rule(t_stack *stack_a, t_stack *stack_b, t_node **head)
{
	t_node	*current;
	t_node	*tail;

	if (!stack_a)
		return ;
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

void	rb_rule(t_node **head)
{
	if (*head)
		*head = (*head)->next;
}

void	rrb_rule(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
}
