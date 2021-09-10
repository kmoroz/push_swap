/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freeing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 14:03:29 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/10 14:23:45 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

void	free_node(t_node **head, int size)
{
	t_node	*temp;

	while (size)
	{
		temp = *head;
		*head = (*head)->prev;
		free(temp);
		size--;
	}
}
