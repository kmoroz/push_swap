/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freeing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 14:03:29 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/15 13:58:20 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap/push_swap.h"
#include <stdlib.h>

void	free_array(char **array, int size)
{
	while (size >= 0)
	{
		free(array[size]);
		size--;
	}
	free(array);
}

int	free_node(t_node **head, int size)
{
	t_node	*temp;

	while (size)
	{
		temp = *head;
		*head = (*head)->prev;
		free(temp);
		size--;
	}
	return (0);
}

void	free_everything(char **array, int array_size,
							t_stack *stack)
{
	if (array)
		free_array(array, array_size);
	if (stack->node)
		free_node(&stack->node, stack->size);
}
