/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:22:02 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/09 11:22:07 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_args(int argc)
{
	if (argc < 2)
		ft_error();
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

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.node = NULL;
	stack_b.node = NULL;
	stack_a.partition = NULL;
	stack_b.partition = NULL;
	stack_a.size = 0;
	stack_b.size = 0;
	validate_args(argc);
	build_stack(argc, argv, &stack_a);
	check_dupes(stack_a.node);
	sort_stack(&stack_a, &stack_b);
}
