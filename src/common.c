/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   common.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 15:34:50 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/14 15:38:24 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap/push_swap.h"

void	put_num_on_stack_reversed(int num, t_node **head)
{
	t_node	*tail;
	t_node	*new_node;

	new_node = ft_lstnew(num);
	if (!new_node)
		ft_error();
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

	if (!head)
		return ;
	tail = head->prev;
	tail->next = NULL;
}

void	make_list_circular(t_node *head)
{
	t_node	*tail;

	if (!head)
		return ;
	tail = head->prev;
	tail->next = head;
}

void	check_dupes(t_node *head, int size)
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
		{
			free_node(&head, size);
			ft_error();
		}
		temp = temp->next;
	}
	make_list_circular(head);
}
