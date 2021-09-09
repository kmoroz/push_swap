/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_a_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 12:04:12 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/09 12:19:07 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

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

void	rra_rule(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
	write(1, "rra\n", 4);
}

void	ra_rule(t_node **head)
{
	if (*head)
		*head = (*head)->next;
	write(1, "ra\n", 3);
}

void	sa_rule(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->node->number;
	stack_a->node->number = stack_a->node->next->number;
	stack_a->node->next->number = temp;
	write(1, "sa\n", 3);
}
