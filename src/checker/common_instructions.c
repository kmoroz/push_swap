/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   common_instructions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 13:37:07 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/13 13:37:46 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss_rule(t_stack *stack_a, t_stack *stack_b)
{
	sa_rule(stack_a);
	sb_rule(stack_b);
}

void	rr_rule(t_node **head_a, t_node **head_b)
{
	ra_rule(head_a);
	rb_rule(head_b);
}

void	rrr_rule(t_node **head_a, t_node **head_b)
{
	rra_rule(head_a);
	rra_rule(head_b);
}
