/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/09 11:25:09 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/09/10 16:53:07 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define SMALL_STACK 5

typedef struct s_stack
{
	t_node		*node;
	int			size;
}				t_stack;

void	sort_stack(t_stack *stack_a, t_stack *stack_b);
void	chunk_sort(t_stack *stack_a, t_stack *stack_b);
int		get_chunk_number(t_stack *stack_a, t_node **head_a);
int		count_chunk_elements(t_stack *stack_a,
			t_node **head_a, int chunk_limit);
int		is_in_first_half(t_stack *stack, t_node **head, int num);
int		count_ra_moves(t_stack *stack_a, t_node **head_a);
int		count_rra_moves(t_stack *stack_a, t_node **head_a);
void	pa_rule(t_stack *stack_a, t_stack *stack_b, t_node **head);
void	rra_rule(t_node **head);
void	ra_rule(t_node **head);
void	sa_rule(t_stack *stack_a);
void	pb_rule(t_stack *stack_a, t_stack *stack_b, t_node **head);
void	rrb_rule(t_node **head);
void	rb_rule(t_node **head);
void	put_num_on_stack_reversed(int num, t_node **head);
int		find_stack_min(t_stack *stack_a, t_node **head_a);
int		find_stack_max(t_stack *stack, t_node **head);
void	traverse_b(t_stack *stack_a, t_stack *stack_b, t_node **head_b);
int		move_top_to_b(t_stack *stack_a, t_stack *stack_b, int chunk_limit);
void	move_closest_to_top(t_stack *stack_a, t_node **head_a);
void	quicksort(t_stack *stack_a, t_stack *stack_b);
void	find_pivot(int size, t_node **head, int *pivot);
int		vals_less_than_pivot_left(t_node **head, int pivot, int size);
void	sort_three(t_stack *stack);
// ------------------------------ common -----------------------------------
void	build_stack(int argc, char **argv, t_stack *stack_a);
void	put_num_on_stack(int num, t_node **head);
void	check_dupes(t_node *head);
int		is_sorted(t_node *stack_a);
void	make_list_linear(t_node *head);
void	make_list_circular(t_node *head);
void	free_array(char **array, int size);
int		free_node(t_node **head, int size);
void	free_everything(char **array, int array_size,
			t_stack *stack);

#endif
