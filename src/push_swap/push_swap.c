/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:22:02 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/10 19:17:41 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	validate_args(int argc, t_stack *stack_a)
{
	if (argc == 1)
		ft_error();
	else if (stack_a->size == 1)
	{
		free_node(&stack_a->node, stack_a->size);
		ft_error();
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.node = NULL;
	stack_b.node = NULL;
	stack_a.size = 0;
	stack_b.size = 0;
	validate_args(argc, &stack_a);
	build_stack(argc, argv, &stack_a);
	validate_args(argc, &stack_a);
	check_dupes(stack_a.node);
	sort_stack(&stack_a, &stack_b);
	free_node(&stack_a.node, stack_a.size);
}
