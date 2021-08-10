#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	t_node		*node;
	int			size;
	t_node		*partition;
}				t_stack;

void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	make_list_linear(t_node *head);
void	make_list_circular(t_node *head);

#endif