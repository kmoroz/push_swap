/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_builder.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:22:33 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/16 09:05:44 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap/push_swap.h"
#include <limits.h>
#include <stdbool.h>

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

void	count_stack_size(t_stack *stack_a, t_node **head)
{
	t_node	*current;
	t_node	*tail;

	if (!stack_a->node)
		return ;
	current = *head;
	tail = current->prev;
	while (current != tail)
	{
		stack_a->size++;
		current = current->next;
	}
	stack_a->size++;
}

void	verify_input(const char *str, t_stack *stack_a, char **array, int size)
{
	int		count;
	bool	error;

	count = 0;
	error = false;
	while (str[count])
	{
		if (!ft_isdigit(str[count]) && str[count] != '-')
			error = true;
		count++;
	}
	if (ft_strlen(str) == 1 && str[0] == '-')
		error = true;
	if (ft_strlen(str) > 11)
		error = true;
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		error = true;
	if (error == true)
	{
		count_stack_size(stack_a, &stack_a->node);
		free_everything(array, size, stack_a);
		ft_error();
	}
}

void	put_num_on_stack(int num, t_node **head)
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
		(*head)->prev = new_node;
		new_node->prev = tail;
		tail->next = new_node;
	}
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
		if (!str)
			ft_error();
		array_size = calculate_array_size(str);
		j = 0;
		while (j < array_size)
		{
			verify_input(str[j], stack_a, str, array_size);
			num = ft_atol(str[j]);
			put_num_on_stack(num, &stack_a->node);
			j++;
		}
		i++;
		free_array(str, array_size);
	}
	count_stack_size(stack_a, &stack_a->node);
}
