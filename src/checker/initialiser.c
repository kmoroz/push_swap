/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialiser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 14:50:03 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/13 14:52:29 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_checker_structs(t_stack *stack_a,
	t_stack *stack_b, t_stack *instructions)
{
	stack_a->node = NULL;
	stack_a->size = 0;
	stack_b->node = NULL;
	stack_b->size = 0;
	instructions->node = NULL;
	instructions->size = 0;
}
