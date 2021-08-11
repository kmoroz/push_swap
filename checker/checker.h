#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../push_swap.h"

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

#endif