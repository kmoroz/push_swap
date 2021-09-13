/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 12:09:47 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/13 11:03:57 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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
