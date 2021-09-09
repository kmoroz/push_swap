/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sort_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:49:43 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/09 11:54:07 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_number(t_stack *stack_a, t_node **head_a)
{
	int	chunk_step;
	int	max;
	int	min;

	max = find_stack_max(stack_a, head_a);
	min = find_stack_min(stack_a, head_a);
	if (stack_a->size <= 100)
		chunk_step = ((max - min) / 5) + 1;
	if (stack_a->size > 100)
		chunk_step = ((max - min) / 12) + 1;
	return (chunk_step);
}

int	count_chunk_elements(t_stack *stack_a, t_node **head_a, int chunk_limit)
{
	int		i;
	t_node	*temp;
	int		count;

	i = stack_a->size;
	temp = *head_a;
	count = 0;
	while (i)
	{
		if (temp->number < chunk_limit)
		{
			temp->is_in_chunk = 1;
			count++;
		}
		temp = temp->next;
		i--;
	}
	return (count);
}

int	is_in_first_half(t_stack *stack, t_node **head, int num)
{
	int		i;
	t_node	*temp;

	temp = *head;
	i = stack->size / 2;
	while (i)
	{
		if (temp->number == num)
			return (1);
		i--;
		temp = temp->next;
	}
	return (0);
}

int	count_ra_moves(t_stack *stack_a, t_node **head_a)
{
	int		i;
	int		count_from_top;
	t_node	*temp;

	i = stack_a->size / 2;
	count_from_top = 0;
	temp = *head_a;
	while (i)
	{
		if (temp->is_in_chunk)
			break ;
		count_from_top++;
		temp = temp->next;
		i--;
	}
	return (count_from_top);
}

int	count_rra_moves(t_stack *stack_a, t_node **head_a)
{
	int		i;
	int		count_from_bottom;
	t_node	*temp;

	i = stack_a->size / 2;
	count_from_bottom = 1;
	temp = (*head_a)->prev;
	while (i)
	{
		if (temp->is_in_chunk)
			break ;
		count_from_bottom++;
		temp = temp->prev;
		i--;
	}
	return (count_from_bottom);
}
