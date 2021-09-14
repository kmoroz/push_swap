/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_b_instructions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 12:02:19 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/14 13:24:03 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	pb_rule(t_stack *stack_a, t_stack *stack_b, t_node **head)
{
	t_node	*current;
	t_node	*tail;

	if (!stack_a->node)
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
	write(1, "pb\n", 3);
	if (stack_a->size == 0)
		stack_a->node = NULL;
}

void	rrb_rule(t_node **head)
{
	if (*head)
		*head = (*head)->prev;
	write(1, "rrb\n", 4);
}

void	rb_rule(t_node **head)
{
	if (*head)
		*head = (*head)->next;
	write(1, "rb\n", 3);
}
