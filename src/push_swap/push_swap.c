/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:22:02 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/14 15:43:15 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.node = NULL;
	stack_b.node = NULL;
	stack_a.size = 0;
	stack_b.size = 0;
	if (argc > 1)
	{
		build_stack(argc, argv, &stack_a);
		if (!stack_a.size)
			exit(0);
		check_dupes(stack_a.node, stack_a.size);
		sort_stack(&stack_a, &stack_b);
		free_node(&stack_a.node, stack_a.size);
	}
}
