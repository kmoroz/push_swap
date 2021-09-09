/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   common.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 15:34:50 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/09 15:37:47 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	make_list_linear(t_node *head)
{
	t_node	*tail;

	tail = head->prev;
	tail->next = NULL;
}

void	make_list_circular(t_node *head)
{
	t_node	*tail;

	tail = head->prev;
	tail->next = head;
}

void	check_dupes(t_node *head)
{
	int		count;
	t_node	*temp;
	t_node	*temp_2;

	make_list_linear(head);
	temp = head;
	while (temp)
	{
		count = 0;
		temp_2 = head;
		while (temp_2)
		{
			if (temp->number == temp_2->number)
				count++;
			temp_2 = temp_2->next;
		}
		if (count > 1)
			ft_error();
		temp = temp->next;
	}
	make_list_circular(head);
}
