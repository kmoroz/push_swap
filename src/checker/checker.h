/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/13 14:05:38 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/13 14:52:57 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap/push_swap.h"

typedef enum e_operation
{
	SA = 1,
	SB = 2,
	SS = 3,
	PA = 4,
	PB = 5,
	RA = 6,
	RB = 7,
	RR = 8,
	RRA = 9,
	RRB = 10,
	RRR = 11,
}	t_operation;

void	sa_rule(t_stack *stack_a);
void	pa_rule(t_stack *stack_a, t_stack *stack_b, t_node **head);
void	pb_rule(t_stack *stack_a, t_stack *stack_b, t_node **head);
void	ra_rule(t_node **head);
void	rra_rule(t_node **head);
void	sb_rule(t_stack *stack_b);
void	ss_rule(t_stack *stack_a, t_stack *stack_b);
void	rb_rule(t_node **head);
void	rr_rule(t_node **head_a, t_node **head_b);
void	rrb_rule(t_node **head);
void	rrr_rule(t_node **head_a, t_node **head_b);
void	apply_instructions(t_node *instructions_head,
			t_stack *stack_a, t_stack *stack_b);
void	init_checker_structs(t_stack *stack_a,
			t_stack *stack_b, t_stack *instructions);

#endif
