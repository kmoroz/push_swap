/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_a_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 14:03:34 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/14 13:25:10 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

void	sa_rule(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->node->number;
	stack_a->node->number = stack_a->node->next->number;
	stack_a->node->next->number = temp;
}

void	pa_rule(t_stack *stack_a, t_stack *stack_b, t_node **head)
{
	t_node	*current;
	t_node	*tail;
	t_node	*next_head;

	if (!stack_b->node)
		return ;
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
	if (stack_b->size == 0)
		stack_b->node = NULL;
}

void	ra_rule(t_node **head)
{
	if (*head)
		*head = (*head)->next;
}

void	rra_rule(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
}
