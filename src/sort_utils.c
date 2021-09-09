/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 12:09:47 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/09 12:12:58 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	put_num_on_stack_reversed(int num, t_node **head)
{
	t_node	*tail;
	t_node	*new_node;

	new_node = ft_lstnew(num);
	if (!*head)
	{
		*head = new_node;
		tail = new_node;
		tail->next = *head;
		tail->prev = *head;
	}
	else
	{
		tail = (*head)->prev;
		new_node->next = *head;
		new_node->prev = tail;
		(*head)->prev = new_node;
		*head = new_node;
		tail->next = *head;
	}
}

int	find_stack_min(t_stack *stack_a, t_node **head_a)
{
	int		min;
	int		i;
	t_node	*temp;

	min = INT_MAX;
	i = stack_a->size;
	temp = *head_a;
	while (i)
	{
		if (min > temp->number)
			min = temp->number;
		temp = temp->next;
		i--;
	}
	return (min);
}

int	find_stack_max(t_stack *stack, t_node **head)
{
	int		max;
	int		i;
	t_node	*temp;

	max = INT_MIN;
	i = stack->size;
	temp = *head;
	while (i)
	{
		if (max < temp->number)
			max = temp->number;
		temp = temp->next;
		i--;
	}
	return (max);
}

int	is_sorted(t_node *stack_a)
{
	t_node	*temp;

	if (!stack_a)
		return (0);
	temp = stack_a;
	while (temp->next != stack_a)
	{
		if (temp->number > temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (1);
}
