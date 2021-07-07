#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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

typedef struct s_stack
{
	t_node		*node;
	int			size;
}				t_stack;

void	ft_error(void);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);

#endif