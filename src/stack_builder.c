/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_builder.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:22:33 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/10 14:05:41 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	calculate_array_size(char **str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

void	verify_input(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if (!ft_isdigit(str[count]) && str[count] != '-')
			ft_error();
		count++;
	}
	if (ft_strlen(str) > 10)
		ft_error();
	if (ft_strlen(str) == 10)
	{
		if (ft_atol(str) > INT_MAX)
			ft_error();
	}
}

void	put_num_on_stack(int num, t_node **head)
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
		(*head)->prev = new_node;
		new_node->prev = tail;
		tail->next = new_node;
	}
}

void	count_stack_size(t_stack *stack_a, t_node **head)
{
	t_node	*current;
	t_node	*tail;

	current = *head;
	tail = current->prev;
	while (current != tail)
	{
		stack_a->size++;
		current = current->next;
	}
	stack_a->size++;
}

void	build_stack(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	int		j;
	char	**str;
	int		num;
	int		array_size;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		array_size = calculate_array_size(str);
		j = 0;
		while (j < array_size)
		{
			verify_input(str[j]);
			num = ft_atol(str[j]);
			put_num_on_stack(num, &stack_a->node);
			j++;
		}
		i++;
		free_array(str, array_size);
	}
	count_stack_size(stack_a, &stack_a->node);
}
