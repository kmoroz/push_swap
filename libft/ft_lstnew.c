/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 12:16:42 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/08/17 15:35:51 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"
#include <stdlib.h>

t_node	*ft_lstnew(int content)
{
	t_node	*new_element;

	new_element = (t_node *)malloc(sizeof(t_node));
	if (!new_element)
		ft_error();
	new_element->number = content;
	new_element->next = NULL;
	new_element->prev = NULL;
	new_element->is_sorted = 0;
	return (new_element);
}
